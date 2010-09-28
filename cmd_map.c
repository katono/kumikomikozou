#include <stdlib.h>
#include <string.h>
#include <cstl/map.h>
#include <cstl/string.h>
#include "Pool.h"
#include "StrToken.h"
#include "lib.h"
#include "led.h"

extern Pool pool;
#define malloc(s)      Pool_malloc(&pool, s)
#define realloc(p, s)  Pool_realloc(&pool, p, s)
#define free(p)        Pool_free(&pool, p)
#define strdup(s)      my_strdup(s)

char *my_strdup(const char *s)
{
	char *p = (char *) malloc(sizeof(char) * (strlen(s) + 1));
	if (p) {
		strcpy(p, s);
	}
	return p;
}

CSTL_STRING_INTERFACE(String, char)
CSTL_STRING_IMPLEMENT(String, char)

CSTL_MAP_INTERFACE(Map, char *, char *)
CSTL_MAP_IMPLEMENT(Map, char *, char *, strcmp)

CSTL_MAP_INTERFACE(ObjMap, char *, Map *)
CSTL_MAP_IMPLEMENT(ObjMap, char *, Map *, strcmp)

static void command_new(StrToken *tok);
static void command_delete(StrToken *tok);
static void command_insert(StrToken *tok);
static void command_erase(StrToken *tok);
static void command_clear(StrToken *tok);
static void command_find(StrToken *tok);
static void command_print(StrToken *tok);
static void command_exit(StrToken *tok);
static void command_help(StrToken *tok);
static void command_led(StrToken *tok);
static void command_dump(StrToken *tok);

typedef void (*cmd_func_t)(StrToken*);
struct Cmd {
	const char *command;
	cmd_func_t func;
};
static const struct Cmd cmd_list[] = {
	{ "new"    , command_new    },
	{ "delete" , command_delete },
	{ "insert" , command_insert },
	{ "erase"  , command_erase  },
	{ "clear"  , command_clear  },
	{ "find"   , command_find   },
	{ "print"  , command_print  },
	{ "p"      , command_print  },
	{ "exit"   , command_exit   },
	{ "help"   , command_help   },
	{ "h"      , command_help   },
	{ "?"      , command_help   },
	{ "led"    , command_led    },
	{ "dump"   , command_dump   },
};

CSTL_MAP_INTERFACE(CmdMap, const char *, cmd_func_t)
CSTL_MAP_IMPLEMENT(CmdMap, const char *, cmd_func_t, strcmp)

static ObjMap *obj_map;
static int exit_flag;

static void Map_erase_ex(Map *map, MapIterator map_iter)
{
	free(*Map_key(map_iter));
	free(*Map_value(map_iter));
	Map_erase(map, map_iter);
}

static void Map_clear_ex(Map *map)
{
	while (!Map_empty(map)) {
		Map_erase_ex(map, Map_begin(map));
	}
}

static void Map_delete_ex(Map *map)
{
	if (!map) return;
	Map_clear_ex(map);
	Map_delete(map);
}

static void ObjMap_erase_ex(ObjMap *om, ObjMapIterator om_iter)
{
	free(*ObjMap_key(om_iter));
	Map_delete_ex(*ObjMap_value(om_iter));
	ObjMap_erase(obj_map, om_iter);
}

static void ObjMap_clear_ex(ObjMap *om)
{
	while (!ObjMap_empty(obj_map)) {
		ObjMap_erase_ex(obj_map, ObjMap_begin(obj_map));
	}
}

static void ObjMap_delete_ex(ObjMap *om)
{
	if (!om) return;
	ObjMap_clear_ex(om);
	ObjMap_delete(om);
}


static void command_new(StrToken *tok)
{
	char *p = 0;
	Map *map = 0;
	if (StrToken_count(tok) < 2) {
		PRINTF0("syntax error.\n");
		return;
	}
	if (ObjMap_find(obj_map, (char *)StrToken_get(tok, 1)) != ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] already exists.\n", StrToken_get(tok, 1));
		return;
	}
	p = strdup(StrToken_get(tok, 1));
	if (!p) goto err;
	map = Map_new();
	if (!map) goto err;
	if (!ObjMap_insert(obj_map, p, map, NULL)) goto err;

	return;
err:
	PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
	Map_delete(map);
	free(p);
}

static void command_delete(StrToken *tok)
{
	ObjMapIterator om_iter;
	if (StrToken_count(tok) < 2) {
		PRINTF0("syntax error.\n");
		return;
	}
	om_iter = ObjMap_find(obj_map, (char *)StrToken_get(tok, 1));
	if (om_iter == ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] doesn't exist.\n", StrToken_get(tok, 1));
		return;
	}

	ObjMap_erase_ex(obj_map, om_iter);
}

static void command_insert(StrToken *tok)
{
	ObjMapIterator om_iter;
	Map *map;
	char *key = 0;
	char *val = 0;
	if (StrToken_count(tok) < 4) {
		PRINTF0("syntax error.\n");
		return;
	}
	om_iter = ObjMap_find(obj_map, (char *)StrToken_get(tok, 1));
	if (om_iter == ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] doesn't exist.\n", StrToken_get(tok, 1));
		return;
	}
	map = *ObjMap_value(om_iter);
	if (Map_find(map, (char *)StrToken_get(tok, 2)) != Map_end(map)) {
		PRINTF1("key[%s] already exists.\n", StrToken_get(tok, 2));
		return;
	}

	key = strdup(StrToken_get(tok, 2));
	if (!key) goto err;
	val = strdup(StrToken_get(tok, 3));
	if (!val) goto err;
	if (!Map_insert(map, key, val, NULL)) goto err;

	return;
err:
	PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
	free(key);
	free(val);
}

static void command_erase(StrToken *tok)
{
	ObjMapIterator om_iter;
	Map *map;
	MapIterator map_iter;
	if (StrToken_count(tok) < 3) {
		PRINTF0("syntax error.\n");
		return;
	}
	om_iter = ObjMap_find(obj_map, (char *)StrToken_get(tok, 1));
	if (om_iter == ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] doesn't exist.\n", StrToken_get(tok, 1));
		return;
	}
	map = *ObjMap_value(om_iter);
	map_iter = Map_find(map, (char *)StrToken_get(tok, 2));
	if (map_iter == Map_end(map)) {
		PRINTF1("key[%s] doesn't exist.\n", StrToken_get(tok, 2));
		return;
	}
	Map_erase_ex(map, map_iter);
}

static void command_clear(StrToken *tok)
{
	ObjMapIterator om_iter;
	Map *map;
	if (StrToken_count(tok) < 2) {
		PRINTF0("syntax error.\n");
		return;
	}
	om_iter = ObjMap_find(obj_map, (char *)StrToken_get(tok, 1));
	if (om_iter == ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] doesn't exist.\n", StrToken_get(tok, 1));
		return;
	}
	map = *ObjMap_value(om_iter);
	Map_clear_ex(map);
}

static void command_find(StrToken *tok)
{
	ObjMapIterator om_iter;
	Map *map;
	MapIterator map_iter;
	if (StrToken_count(tok) < 3) {
		PRINTF0("syntax error.\n");
		return;
	}
	om_iter = ObjMap_find(obj_map, (char *)StrToken_get(tok, 1));
	if (om_iter == ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] doesn't exist.\n", StrToken_get(tok, 1));
		return;
	}
	map = *ObjMap_value(om_iter);
	map_iter = Map_find(map, (char *)StrToken_get(tok, 2));
	if (map_iter == Map_end(map)) {
		PRINTF1("key[%s] doesn't exist.\n", StrToken_get(tok, 2));
		return;
	}
	PRINTF1(" [%s, ", *Map_key(map_iter));
	PRINTF1("%s]\n", *Map_value(map_iter));
}

static void map_print(const char *name, Map *map)
{
	MapIterator map_iter;
	PRINTF1("%s\n", name);
	for (map_iter = Map_begin(map); map_iter != Map_end(map); map_iter = Map_next(map_iter)) {
		PRINTF1(" [%s, ", *Map_key(map_iter));
		PRINTF1("%s]\n", *Map_value(map_iter));
	}
}

static void command_print(StrToken *tok)
{
	ObjMapIterator om_iter;
	if (StrToken_count(tok) < 2) {
		for (om_iter = ObjMap_begin(obj_map); om_iter != ObjMap_end(obj_map); om_iter = ObjMap_next(om_iter)) {
			map_print(*ObjMap_key(om_iter), *ObjMap_value(om_iter));
		}
		return;
	}
	om_iter = ObjMap_find(obj_map, (char *)StrToken_get(tok, 1));
	if (om_iter == ObjMap_end(obj_map)) {
		PRINTF1("obj[%s] doesn't exist.\n", StrToken_get(tok, 1));
		return;
	}
	map_print(*ObjMap_key(om_iter), *ObjMap_value(om_iter));
}

static void command_exit(StrToken *tok)
{
	exit_flag = 1;
}

static void command_help(StrToken *tok)
{
	PRINTF0("commands:\n");
	PRINTF0("  new NAME\n");
	PRINTF0("  delete NAME\n");
	PRINTF0("  insert NAME KEY VALUE\n");
	PRINTF0("  erase NAME KEY\n");
	PRINTF0("  clear NAME\n");
	PRINTF0("  find NAME KEY\n");
	PRINTF0("  print [NAME]\n");
}

static void command_led(StrToken *tok)
{
	if (StrToken_count(tok) < 3) {
		PRINTF0("syntax error.\n");
		return;
	}
	if (strcmp(StrToken_get(tok, 1), "1") == 0) {
		if (strcmp(StrToken_get(tok, 2), "on") == 0) {
			led_on(LED1);
		} else if (strcmp(StrToken_get(tok, 2), "off") == 0) {
			led_off(LED1);
		} else {
			PRINTF0("syntax error.\n");
		}
	} else if (strcmp(StrToken_get(tok, 1), "2") == 0) {
		if (strcmp(StrToken_get(tok, 2), "on") == 0) {
			led_on(LED2);
		} else if (strcmp(StrToken_get(tok, 2), "off") == 0) {
			led_off(LED2);
		} else {
			PRINTF0("syntax error.\n");
		}
	} else {
		PRINTF0("syntax error.\n");
	}
}

static void command_dump(StrToken *tok)
{
	unsigned long addr, size;
	if (StrToken_count(tok) < 3) {
		PRINTF0("syntax error.\n");
		return;
	}
	addr = strtoul(StrToken_get(tok, 1), 0, 0);
	size = strtoul(StrToken_get(tok, 2), 0, 0);
	PRINTF0("\n");
	hexdump((const void *) addr, size);
	PRINTF0("\n");
}

const char *getline(String *str)
{
	char c;
	String_clear(str);
	String_shrink(str, 31);
	do {
		c = getc();
		if (c == '\b') {
			/* Backspace */
			if (!String_empty(str)) {
				String_pop_back(str);
			}
		} else if (c != '\n') {
			if (!String_push_back(str, c)) {
				PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
				return 0;
			}
		}
	} while (c != '\n');
	return String_c_str(str);
}


void cmd_map(void)
{
	size_t i;
	String *buf = 0;
	CmdMap *cmds = 0;
	obj_map = 0;

	buf = String_new();
	if (!buf) {
		PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
		goto err;
	}
	cmds = CmdMap_new();
	if (!cmds) {
		PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
		goto err;
	}
	for (i = 0; i < sizeof cmd_list / sizeof cmd_list[0]; i++) {
		if (!CmdMap_insert(cmds, cmd_list[i].command, cmd_list[i].func, NULL)) {
			PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
			goto err;
		}
	}
	obj_map = ObjMap_new();
	if (!obj_map) {
		PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
		goto err;
	}

	exit_flag = 0;
	while (!exit_flag) {
		const char *line;
		StrToken *tok;
		CmdMapIterator cmd_iter;

		PRINTF0(">");
		line = getline(buf);
		if (!line) {
			continue;
		}

		tok = StrToken_new(line, " \t");
		if (!tok) {
			PRINTF2("mem alloc failed: %s(%d)\n", __FILE__, __LINE__);
			continue;
		}
		if (StrToken_count(tok) == 0) {
			goto next;
		}
		cmd_iter = CmdMap_find(cmds, StrToken_get(tok, 0));
		if (cmd_iter == CmdMap_end(cmds)) {
			goto next;
		}
		(*CmdMap_value(cmd_iter))(tok);

next:
		StrToken_delete(tok);
	}
err:
	ObjMap_delete_ex(obj_map);
	CmdMap_delete(cmds);
	String_delete(buf);
}

