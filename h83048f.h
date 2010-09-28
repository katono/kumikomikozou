/* ------------------------------------------------------------------------- */
/*  H8/3048F 用 ヘッダファイル                                               */
/*  全てのデバイスで検証をしている訳では無いので、使用にあたっては十分注意   */
/*  が必要です。                                                             */
/*  この辺が個人の限界と言う事で、バグ報告待ってます。                       */
/*                                                                           */
/*  日立統一ヘッダーファイル バージョン２との違い                            */
/*  日立のヘッダーファイルでは16bit長のフィールドは intで表しています。      */
/*  このヘッダーファイルもそれに倣おうかとも思いましたが、shortで表す事に    */
/*  しました。と言うのも SHなんかも結構 H8で作成したコーディングそのまま動   */
/*  いちゃう事が多いのですが(特に SCI等)、例えば ADはやはり10bitでその長さ   */
/*  は H8も SHも変わらず、レジスタは16bitでアクセスします。あっちは intで    */
/*  こっちは shortとなるのがイマイチ嫌なので、両方とも揃える為に shortで宣   */
/*  言しています。                                                           */
/*  また、日立コンパイラー バージョン３以上では問題とならないビットフィー    */
/*  ルドの省略ですが、秋月コンパイラ、つまり日立コンパイラ バージョン２の    */
/*  サブセットではコンパイルエラーとなるので、適当なフィールド名を充ててい   */
/*  ます。                                                                   */
/*                                                                           */
/*                                   Copyright (C) 1998-2002 by Project HOS  */
/* ------------------------------------------------------------------------- */


#ifndef __PROJECT_HOS__H8_3048_H_
#define __PROJECT_HOS__H8_3048_H_

/* IO デバイスアドレス定義 */
#define	__DMAC0A_ADD__	0xffff20	/* DMAC0Aレジスタスタートアドレス */
#define	__DMAC0B_ADD__	0xffff28	/* DMAC0Bレジスタスタートアドレス */
#define	__DMAC1A_ADD__	0xffff30	/* DMAC1Aレジスタスタートアドレス */
#define	__DMAC1B_ADD__	0xffff38	/* DMAC1Bレジスタスタートアドレス */
#define	__DMAC0_ADD__	0xffff20	/* DMAC0レジスタスタートアドレス */
#define	__DMAC1_ADD__	0xffff30	/* DMAC1レジスタスタートアドレス */
#define	__FLASH_ADD__	0xffff40	/* FLASHレジスタスタートアドレス */
#define	__DA_ADD__		0xffff5c	/* DAレジスタスタートアドレス */
#define	__DIVCR_ADD__	0xffff5d	/* DIVCRレジスタスタートアドレス */
#define	__MSTCR_ADD__	0xffff5e	/* MSTCRレジスタスタートアドレス */
#define	__BSC_ADD__		0xffff5f	/* BSCレジスタスタートアドレス */
#define	__ITU_COMM_ADD__	0xffff60	/* ITU共通レジスタスタートアドレス */
#define	__ITU0_ADD__	0xffff64	/* ITU0レジスタスタートアドレス */
#define	__ITU1_ADD__	0xffff6e	/* ITU1レジスタスタートアドレス */
#define	__ITU2_ADD__	0xffff78	/* ITU2レジスタスタートアドレス */
#define	__ITU3_ADD__	0xffff82	/* ITU3レジスタスタートアドレス */
#define	__ITU4_ADD__	0xffff92	/* ITU4レジスタスタートアドレス */
#define	__TPC_ADD__		0xffffa0	/* TPCレジスタスタートアドレス */
#define	__WDT_ADD__		0xffffa8	/* WDTレジスタスタートアドレス */
#define	__RFSHC_ADD__	0xffffa8	/* RFSHCレジスタスタートアドレス */
#define	__SCI0_ADD__	0xffffb0	/* SCI0レジスタスタートアドレス */
#define	__SCI1_ADD__	0xffffb8	/* SCI1レジスタスタートアドレス */
#define	__P1_ADD__		0xffffc0	/* PORT1レジスタスタートアドレス */
#define	__P2_ADD__		0xffffc1	/* PORT2レジスタスタートアドレス */
#define	__P3_ADD__		0xffffc4	/* PORT3レジスタスタートアドレス */
#define	__P4_ADD__		0xffffc5	/* PORT4レジスタスタートアドレス */
#define	__P5_ADD__		0xffffc8	/* PORT5レジスタスタートアドレス */
#define	__P6_ADD__		0xffffc9	/* PORT6レジスタスタートアドレス */
#define	__P8_ADD__		0xffffcd	/* PORT8レジスタスタートアドレス */
#define	__P7_ADD__		0xffffce	/* PORT7レジスタスタートアドレス */
#define	__P9_ADD__		0xffffd0	/* PORT9レジスタスタートアドレス */
#define	__PA_ADD__		0xffffd1	/* PORT Aレジスタスタートアドレス */
#define	__PB_ADD__		0xffffd4	/* PORT Bレジスタスタートアドレス */
#define	__AD_ADD__		0xffffe0	/* ADレジスタスタートアドレス */
#define	__MDCR_ADD__	0xfffff1	/* MDCRレジスタスタートアドレス */
#define	__SYSCR_ADD__	0xfffff2	/* SYSCRレジスタスタートアドレス */
#define	__INTC_ADD__	0xfffff4	/* INTCレジスタスタートアドレス */


/* モードコントロールレジスタ */
union __MDCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:5;		/*予約*/
		unsigned char MDS:3;		/*モードセレクト*/
	} BIT;
};
#define	MDCR	(*(volatile union __MDCR_REG__ *)__MDCR_ADD__)	/* ビットフィールド用 */

/* システムコントローラー */
union __SYSCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char SSBY:1;		/*ソフトウエアスタンバイ*/
		unsigned char STS:3;		/*スタンバイタイマセレクタ*/
		unsigned char UE:1;			/*ユーザービットイネーブル*/
		unsigned char NMIEG:1;		/*NMIエッジセレクト*/
		unsigned char rsv1:1;		/*予約*/
		unsigned char RAME:1;		/*RAMイネーブル*/
	} BIT;
};
#define	SYSCR	(*(volatile union __SYSCR_REG__ *)__SYSCR_ADD__)	/* ビットフィールド用 */

/* 割込みコントローラー */
struct __INTC_REG__
{
	union								/*ISCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*予約*/
			unsigned char IRQ5SC:1;		/*IRQセンスコントロール 5*/
			unsigned char IRQ4SC:1;		/*IRQセンスコントロール 4*/
			unsigned char IRQ3SC:1;		/*IRQセンスコントロール 3*/
			unsigned char IRQ2SC:1;		/*IRQセンスコントロール 2*/
			unsigned char IRQ1SC:1;		/*IRQセンスコントロール 1*/
			unsigned char IRQ0SC:1;		/*IRQセンスコントロール 0*/
		} BIT;
	} ISCR;
	union								/*IERレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*予約*/
			unsigned char IRQ5E:1;		/*IRQイネーブルレジスタ 5*/
			unsigned char IRQ4E:1;		/*IRQイネーブルレジスタ 4*/
			unsigned char IRQ3E:1;		/*IRQイネーブルレジスタ 3*/
			unsigned char IRQ2E:1;		/*IRQイネーブルレジスタ 2*/
			unsigned char IRQ1E:1;		/*IRQイネーブルレジスタ 1*/
			unsigned char IRQ0E:1;		/*IRQイネーブルレジスタ 0*/
		} BIT;
	} IER;
	union
	{								/*ISRレジスタ*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*予約*/
			unsigned char IRQ5F:1;		/*IRQステータスレジスタ 5*/
			unsigned char IRQ4F:1;		/*IRQステータスレジスタ 4*/
			unsigned char IRQ3F:1;		/*IRQステータスレジスタ 3*/
			unsigned char IRQ2F:1;		/*IRQステータスレジスタ 2*/
			unsigned char IRQ1F:1;		/*IRQステータスレジスタ 1*/
			unsigned char IRQ0F:1;		/*IRQステータスレジスタ 0*/
		} BIT;
	} ISR;
	char	rsv2;						/*空き*/
	union								/*IPRAレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char _IRQ0:1;		/*IREQ0 割込みのプライオリティレベル設定*/
			unsigned char _IRQ1:1;		/*IREQ1 割込みのプライオリティレベル設定*/
			unsigned char _IRQ23:1;		/*IREQ23 割込みのプライオリティレベル設定*/
			unsigned char _IRQ45:1;		/*IREQ45 割込みのプライオリティレベル設定*/
			unsigned char _WDT:1;		/*WDT、リフレッシュコントロラーの割込みのプライオリティレベル設定*/
			unsigned char _ITU0:1;		/*ITU0 割込みのプライオリティレベル設定*/
			unsigned char _ITU1:1;		/*ITU1 割込みのプライオリティレベル設定*/
			unsigned char _ITU2:1;		/*ITU2 割込みのプライオリティレベル設定*/
		} BIT;
	} IPRA;
	union
	{								/*IPRBレジスタ*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char _ITU3:1;		/*ITU3 割込みのプライオリティレベル設定*/
			unsigned char _ITU4:1;		/*ITU4 割込みのプライオリティレベル設定*/
			unsigned char _DMAC:1;		/*DMAC0、1 割込みのプライオリティレベル設定*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char _SCI0:1;		/*SCI0 割込みのプライオリティレベル設定*/
			unsigned char _SCI1:1;		/*SCI1 割込みのプライオリティレベル設定*/
			unsigned char _AD:1;		/*AD 割込みのプライオリティレベル設定*/
			unsigned char rsv2:1;		/*予約*/
		} BIT;
	} IPRB;
};
#define	INTC	(*(volatile struct __INTC_REG__ *)__INTC_ADD__)	/* ビットフィールド用 */

/* バスコントローラー */
struct __BSC_REG__
{
	union								/*CSCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CS7E:1;		/*チップセレクトイネーブル 7*/
			unsigned char CS6E:1;		/*チップセレクトイネーブル 6*/
			unsigned char CS5E:1;		/*チップセレクトイネーブル 5*/
			unsigned char CS4E:1;		/*チップセレクトイネーブル 4*/
			unsigned char rsv1:4;		/*予約*/
		} BIT;
	} CSCR;
	char	rsv1[ 0xffffec - 0xffff5f - 1 ];	/*空き*/
	union								/*ABWCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ABW7:1;		/*エリア バス幅 コントロール 7*/
			unsigned char ABW6:1;		/*エリア バス幅 コントロール 6*/
			unsigned char ABW5:1;		/*エリア バス幅 コントロール 5*/
			unsigned char ABW4:1;		/*エリア バス幅 コントロール 4*/
			unsigned char ABW3:1;		/*エリア バス幅 コントロール 3*/
			unsigned char ABW2:1;		/*エリア バス幅 コントロール 2*/
			unsigned char ABW1:1;		/*エリア バス幅 コントロール 2*/
			unsigned char ABW0:1;		/*エリア バス幅 コントロール 0*/
		} BIT;
	} ABWCR;
	union								/*ASTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char AST7:1;		/*アクセスステートコントロールレジスタ 7*/
			unsigned char AST6:1;		/*アクセスステートコントロールレジスタ 6*/
			unsigned char AST5:1;		/*アクセスステートコントロールレジスタ 5*/
			unsigned char AST4:1;		/*アクセスステートコントロールレジスタ 4*/
			unsigned char AST3:1;		/*アクセスステートコントロールレジスタ 3*/
			unsigned char AST2:1;		/*アクセスステートコントロールレジスタ 2*/
			unsigned char AST1:1;		/*アクセスステートコントロールレジスタ 2*/
			unsigned char AST0:1;		/*アクセスステートコントロールレジスタ 0*/
		} BIT;
	} ASTCR;
	union								/*WCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*予約*/
			unsigned char WMS:2;		/*ウエイトモードセレクト*/
			unsigned char WC:2;			/*ウエイトカウント*/
		} BIT;
	} WCR;
	union								/*WCERレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char WCE7:1;		/*ウエイトステートコントローライネーブルレジスタ 7*/
			unsigned char WCE6:1;		/*ウエイトステートコントローライネーブルレジスタ 6*/
			unsigned char WCE5:1;		/*ウエイトステートコントローライネーブルレジスタ 5*/
			unsigned char WCE4:1;		/*ウエイトステートコントローライネーブルレジスタ 4*/
			unsigned char WCE3:1;		/*ウエイトステートコントローライネーブルレジスタ 3*/
			unsigned char WCE2:1;		/*ウエイトステートコントローライネーブルレジスタ 2*/
			unsigned char WCE1:1;		/*ウエイトステートコントローライネーブルレジスタ 2*/
			unsigned char WCE0:1;		/*ウエイトステートコントローライネーブルレジスタ 0*/
		} BIT;
	} WCER;
	char	rsv2[ 0xfffff3 - 0xffffef - 1 ];	/*空き*/
	union								/*BRCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char A23E:1;		/*アドレス23 イネーブル*/
			unsigned char A22E:1;		/*アドレス22 イネーブル*/
			unsigned char A21E:1;		/*アドレス21 イネーブル*/
			unsigned char rsv1:4;		/*予約*/
			unsigned char BRLE:1;		/*バスリリースイネーブル*/
		} BIT;
	} BRCR;
};
#define	BSC		(*(volatile struct __BSC_REG__ *)__BSC_ADD__)	/* ビットフィールド用 */


/* リフレッシュコントローラー */
struct __RFSHC_REG__
{
	union								/*RFSHCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char SRFMD:1;		/*セルフリフレッシュモード*/
			unsigned char PSRAME:1;		/*PSRAM イネーブル*/
			unsigned char DRAME:1;		/*DRAM イネーブル*/
			unsigned char CASWE:1;		/*ストローブモードセレクト*/
			unsigned char M9M8:1;		/*アドレスマルチプレックスモードセレクト*/
			unsigned char RFSHE:1;		/*リフレッシュ端子イネーブル、日立のヘッダーはPFSHEとなっている*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char RCYCE:1;		/*リフレッシュサイクルイネーブル*/
		} BIT;
	} RFSHCR;
	union								/*RTMCSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CMF:1;		/*コンペアマッチフラグ*/
			unsigned char CMIE:1;		/*コンペアマッチインタラプトイネーブル*/
			unsigned char CKS:3;		/*クロックセレクト*/
			unsigned char rsv1:3;		/*予約*/
		} BIT;
	} RTMCSR;
	unsigned char	RTCNT;				/*リフレッシュタイマカウンタ*/
	unsigned char	RTCOR;				/*リフレッシュタイムコンスタントレジスタ*/
};
#define	RFSHC	(*(volatile struct __RFSHC_REG__ *)__RFSHC_ADD__)	/* ビットフィールド用 */


/* DMAコントローラー */
/* ショートアドレス */
struct __DMAC_SHORT_REG__
{
	void	*MAR;						/*メモリアドレスレジスタ*/
	unsigned short	ETCR;				/*転送カウントレジスタ*/
	unsigned char	IOAR;				/*I/O アドレスレジスタ*/
	union								/*DTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTE:1;		/*データトランスファイネーブル*/
			unsigned char DTSZ:1;		/*データトランスファサイズ*/
			unsigned char DTID:1;		/*データトランスファインクリメント/デクリメント*/
			unsigned char RPE:1;		/*リピートイネーブル*/
			unsigned char DTIE:1;		/*データトランスファインタラプトイネーブル*/
			unsigned char DTS:3;		/*データトランスファセレクト*/
		} BIT;
	} DTCR;
};
/* フルアドレス */
struct __DMAC_FULL_REG__
{
	void	*MARA;						/*メモリアドレスレジスタ*/
	unsigned short	ETCRA;				/*転送カウントレジスタ*/
	char	rsv1;						/*空き*/
	union								/*DTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTE:1;		/*データトランスファイネーブル*/
			unsigned char DTSZ:1;		/*データトランスファサイズ*/
			unsigned char SAID:1;		/*ソースアドレスインクリメント/デクリメント*/
			unsigned char SAIDE:1;		/*ソースアドレスインクリメント/デクリメントイネーブル*/
			unsigned char DTIE:1;		/*データトランスファインタラプトイネーブル*/
			unsigned char DTS:3;		/*データトランスファセレクト*/
		} BIT;
	} DTCRA;
	void	*MARB;						/*メモリアドレスレジスタ*/
	unsigned short	ETCRB;				/*転送カウントレジスタ*/
	char	rsv2;						/*空き*/
	union								/*DTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTME:1;		/*データトランスファマスタイネーブル*/
			unsigned char rsv1:1;		/*予約*/
			unsigned char DAID:1;		/*ディスティネーションアドレスインクリメント/デクリメント*/
			unsigned char DAIDE:1;		/*ディスティネーションアドレスインクリメント/デクリメントイネーブル*/
			unsigned char TMS:1;		/*トランスファモードセレクト*/
			unsigned char DTS:3;		/*データトランスファセレクト*/
		} BIT;
	} DTCRB;
};
#define	DMAC0A	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC0A_ADD__)	/* ビットフィールド用 */
#define	DMAC0B	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC0B_ADD__)	/* ビットフィールド用 */
#define	DMAC1A	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC1A_ADD__)	/* ビットフィールド用 */
#define	DMAC1B	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC1B_ADD__)	/* ビットフィールド用 */
#define	DMAC0	(*(volatile struct __DMAC_FULL_REG__ *)__DMAC0_ADD__)	/* ビットフィールド用 */
#define	DMAC1	(*(volatile struct __DMAC_FULL_REG__ *)__DMAC1_ADD__)	/* ビットフィールド用 */


/* IOポート */
/*DDRレジスタ、DRレジスタは共通で利用できる*/
struct __IO_PORT_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit7*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};

#define	P1		(*(volatile struct __IO_PORT_REG__ *)__P1_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_2_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit7*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
	char rsv2[ 0xffffd8 - 0xffffc3 - 1 ];	/*空き*/
	union								/*PCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit7*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} PCR;
};
#define	P2		(*(volatile struct __IO_PORT_2_REG__ *)__P2_ADD__)	/* ビットフィールド用 */

#define	P3		(*(volatile struct __IO_PORT_REG__ *)__P3_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_4_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit7*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
	char rsv2[ 0xffffda - 0xffffc7 - 1 ];	/*空き*/
	union								/*PCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit7*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} PCR;
};
#define	P4		(*(volatile struct __IO_PORT_4_REG__ *)__P4_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_5_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*該当bit無し*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
	char rsv2[ 0xffffdb - 0xffffca - 1 ];	/*空き*/
	union								/*PCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*該当bit無し*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} PCR;
};
#define	P5		(*(volatile struct __IO_PORT_5_REG__ *)__P5_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_6_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*該当bit無し*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};
#define	P6		(*(volatile struct __IO_PORT_6_REG__ *)__P6_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_7_REG__
{
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit7*/
			unsigned char B6:1;			/*bit6*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};
#define	P7		(*(volatile struct __IO_PORT_7_REG__ *)__P7_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_8_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*該当bit無し*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};
#define	P8		(*(volatile struct __IO_PORT_8_REG__ *)__P8_ADD__)	/* ビットフィールド用 */

struct __IO_PORT_9_REG__
{
	unsigned char DDR;					/*DDRレジスタ*/
	char rsv1;							/*空き*/
	union								/*DRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*該当bit無し*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};
#define	P9		(*(volatile struct __IO_PORT_9_REG__ *)__P9_ADD__)	/* ビットフィールド用 */

#define	PA		(*(volatile struct __IO_PORT_REG__ *)__PA_ADD__)	/* ビットフィールド用 */

#define	PB		(*(volatile struct __IO_PORT_REG__ *)__PB_ADD__)	/* ビットフィールド用 */


/* ITU */
/*ITU共通レジスタ*/
struct __ITU_COMMON_REG__
{
	union								/*TSTRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*未使用*/
			unsigned char STR4:1;		/*カウンタスタート 4*/
			unsigned char STR3:1;		/*カウンタスタート 3*/
			unsigned char STR2:1;		/*カウンタスタート 2*/
			unsigned char STR1:1;		/*カウンタスタート 1*/
			unsigned char STR0:1;		/*カウンタスタート 0*/
		} BIT;
	} TSTR;
	union								/*TSNCレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*未使用*/
			unsigned char SYNC4:1;		/*タイマ同期 4*/
			unsigned char SYNC3:1;		/*タイマ同期 3*/
			unsigned char SYNC2:1;		/*タイマ同期 2*/
			unsigned char SYNC1:1;		/*タイマ同期 1*/
			unsigned char SYNC0:1;		/*タイマ同期 0*/
		} BIT;
	} TSNC;
	union								/*TMDRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char MDF:1;		/*位相係数モード*/
			unsigned char FDIR:1;		/*フラグディレクション*/
			unsigned char PWM4:1;		/*PWMモード 4*/
			unsigned char PWM3:1;		/*PWMモード 3*/
			unsigned char PWM2:1;		/*PWMモード 2*/
			unsigned char PWM1:1;		/*PWMモード 1*/
			unsigned char PWM0:1;		/*PWMモード 0*/
		} BIT;
	} TMDR;
	union								/*TFCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*未使用*/
			unsigned char CMD:2;		/*コンビネーションモード 1*/
			unsigned char BFB4:1;		/*バッファ動作 B4*/
			unsigned char BFA4:1;		/*バッファ動作 A4*/
			unsigned char BFB3:1;		/*バッファ動作 B3*/
			unsigned char BFA3:1;		/*バッファ動作 A3*/
		} BIT;
	} TFCR;
	char	rsv[ 0xffff90 - 0xffff63 - 1 ];	/*空き*/
	union								/*TOERレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*未使用*/
			unsigned char EXB4:1;		/*マスターイネーブル TOCXB4*/
			unsigned char EXA4:1;		/*マスターイネーブル TOCXA4*/
			unsigned char EB3:1;		/*マスターイネーブル TIOCB3*/
			unsigned char EB4:1;		/*マスターイネーブル TIOCB4*/
			unsigned char EA4:1;		/*マスターイネーブル TIOCA4*/
			unsigned char EA3:1;		/*マスターイネーブル TIOCA3*/
		} BIT;
	} TOER;
	union								/*TOCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*未使用*/
			unsigned char XTGD:1;		/*外部トリガディスエーブル*/
			unsigned char rsv2:2;		/*未使用*/
			unsigned char OLS4:1;		/*出力レベルセレクト 4*/
			unsigned char OLS3:1;		/*出力レベルセレクト 3*/
		} BIT;
	} TOCR;
};

#define	ITU		(*(volatile struct __ITU_COMMON_REG__ *)__ITU_COMM_ADD__)	/* ビットフィールド用 */

/*ITU個別レジスタ*/
struct __ITU_TYPE0_REG__
{
	union								/*TCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char CCLR:2;		/*カウンタクリア*/
			unsigned char CKEG:2;		/*クロックエッジ*/
			unsigned char TPSC:3;		/*タイマプリスケーラ*/
		} BIT;
	} TCR;
	union								/*TIORレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char IOB:3;		/*I/O コントロール*/
			unsigned char rsv2:1;		/*未使用*/
			unsigned char IOA:3;		/*I/O コントロール*/
		} BIT;
	} TIOR;
	union								/*TIERレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*未使用*/
			unsigned char OVIE:1;		/*オーバーフローインタラプトイネーブル*/
			unsigned char IMIEB:1;		/*インプットキャプチャ/コンペアマッチインタラプトイネーブル B*/
			unsigned char IMIEA:1;		/*インプットキャプチャ/コンペアマッチインタラプトイネーブル A*/
		} BIT;
	} TIER;
	union								/*TSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*未使用*/
			unsigned char OVF:1;		/*オーバーフローフラグ*/
			unsigned char IMFB:1;		/*インプットキャプチャ/コンペアマッチフラグ B*/
			unsigned char IMFA:1;		/*インプットキャプチャ/コンペアマッチフラグ A*/
		} BIT;
	} TSR;
	unsigned short	TCNT;				/*16bit タイマカウンタ*/
	unsigned short	GRA;				/*ジェネラルレジスタ A*/
	unsigned short	GRB;				/*ジェネラルレジスタ B*/
};

struct __ITU_TYPE3_REG__
{
	union								/*TCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char CCLR:2;		/*カウンタクリア*/
			unsigned char CKEG:2;		/*クロックエッジ*/
			unsigned char TPSC:3;		/*タイマプリスケーラ*/
		} BIT;
	} TCR;
	union								/*TIORレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*未使用*/
			unsigned char IOB:3;		/*I/O コントロール*/
			unsigned char rsv2:1;		/*未使用*/
			unsigned char IOA:3;		/*I/O コントロール*/
		} BIT;
	} TIOR;
	union								/*TIERレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*未使用*/
			unsigned char OVIE:1;		/*オーバーフローインタラプトイネーブル*/
			unsigned char IMIEB:1;		/*インプットキャプチャ/コンペアマッチインタラプトイネーブル B*/
			unsigned char IMIEA:1;		/*インプットキャプチャ/コンペアマッチインタラプトイネーブル A*/
		} BIT;
	} TIER;
	union								/*TSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*未使用*/
			unsigned char OVF:1;		/*オーバーフローフラグ*/
			unsigned char IMFB:1;		/*インプットキャプチャ/コンペアマッチフラグ B*/
			unsigned char IMFA:1;		/*インプットキャプチャ/コンペアマッチフラグ A*/
		} BIT;
	} TSR;
	unsigned short	TCNT;				/*16bit タイマカウンタ*/
	unsigned short	GRA;				/*ジェネラルレジスタ A*/
	unsigned short	GRB;				/*ジェネラルレジスタ B*/
	unsigned short	BRA;				/*バッファレジスタ A*/
	unsigned short	BRB;				/*バッファレジスタ B*/
};

#define	ITU0	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU0_ADD__)	/* ビットフィールド用 */
#define	ITU1	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU1_ADD__)	/* ビットフィールド用 */
#define	ITU2	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU2_ADD__)	/* ビットフィールド用 */
#define	ITU3	(*(volatile struct __ITU_TYPE3_REG__ *)__ITU3_ADD__)	/* ビットフィールド用 */
#define	ITU4	(*(volatile struct __ITU_TYPE3_REG__ *)__ITU4_ADD__)	/* ビットフィールド用 */


/* プログラマブルタイミングパターンコントローラー */
struct __TPC_REG__
{
	union								/*TPMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*未使用*/
			unsigned char G3NOV:1;		/*グループ 3 ノンオーバーラップ*/
			unsigned char G2NOV:1;		/*グループ 2 ノンオーバーラップ*/
			unsigned char G1NOV:1;		/*グループ 1 ノンオーバーラップ*/
			unsigned char G0NOV:1;		/*グループ 0 ノンオーバーラップ*/
		} BIT;
	} TPMR;
	union								/*TPCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char G3CMS:2;		/*グループ 3 コンペアマッチセレクト*/
			unsigned char G2CMS:2;		/*グループ 2 コンペアマッチセレクト*/
			unsigned char G1CMS:2;		/*グループ 1 コンペアマッチセレクト*/
			unsigned char G0CMS:2;		/*グループ 0 コンペアマッチセレクト*/
		} BIT;
	} TPCR;
	union								/*NDERBレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B15:1;		/*bit 15*/
			unsigned char B14:1;		/*bit 14*/
			unsigned char B13:1;		/*bit 13*/
			unsigned char B12:1;		/*bit 12*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDERB;
	union								/*NDERAレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit 7*/
			unsigned char B6:1;			/*bit 6*/
			unsigned char B5:1;			/*bit 5*/
			unsigned char B4:1;			/*bit 4*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDERA;
	union								/*NDRB1レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B15:1;		/*bit 15*/
			unsigned char B14:1;		/*bit 14*/
			unsigned char B13:1;		/*bit 13*/
			unsigned char B12:1;		/*bit 12*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDRB1;
	union								/*NDRA1レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char B7:1;			/*bit 7*/
			unsigned char B6:1;			/*bit 6*/
			unsigned char B5:1;			/*bit 5*/
			unsigned char B4:1;			/*bit 4*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDRA1;
	union								/*NDRB2レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*未使用*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDRB2;
	union								/*NDRA2レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*未使用*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDRA2;
};
#define	TPC	(*(volatile struct __TPC_REG__ *)__TPC_ADD__)	/* ビットフィールド用 */


/* ウオッチドッグタイマー */
union __WDT_REG__
{
	/*読み込み専用*/
	struct
	{
		union								/*DTSCRレジスタ*/
		{
			unsigned char BYTE;				/*Byte Access*/
			struct
			{
				unsigned char OVF:1;		/*オーバーフローフラグ*/
				unsigned char WTIT:1;		/*タイマモードセレクト*/
				unsigned char TME:1;		/*タイマイネーブル*/
				unsigned char rsv1:2;		/*予約*/
				unsigned char CKS:3;		/*クロックセレクト*/
			} BIT;
		} TSCR;
		unsigned char	TCNT;				/*TCNTレジスタ*/
		char	rsv1;						/*空き*/
		union								/*RSTCSRレジスタ*/
		{
			unsigned char BYTE;				/*Byte Access*/
			struct
			{
				unsigned char WRST:1;		/*ウオッチドッグタイマリセット*/
				unsigned char RSTOE:1;		/*リセット出力イネーブル*/
				unsigned char rsv1:6;		/*予約*/
			} BIT;
		} RSTCSR;
	} READ;
	/*書き込み専用*/
	struct
	{
		unsigned short	TSCR;
		unsigned short	RSTCSR;
	} WRITE;
};
#define	WDT		(*(volatile union __WDT_REG__ *)__WDT_ADD__)	/* ビットフィールド用 */


/* シリアルコミュニケーションインターフェース */
struct __SCI0_REG__
{
	union								/*SMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CA:1;			/*コミュニケーションモード、(注)スマートカードインタフェースではGMとなる*/
			unsigned char CHR:1;		/*キャラクタレングス*/
			unsigned char PE:1;			/*パリティイネーブル*/
			unsigned char OE:1;			/*パリティモード*/
			unsigned char STOP:1;		/*ストップビットレングス*/
			unsigned char MP:1;			/*マルチプロセッサモード*/
			unsigned char CKS:2;		/*クロックセレクト*/
		} BIT;
	} SMR;
	unsigned char	BRR;				/*ビットレートレジスタ*/
	union								/*SCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TIE:1;		/*トランスミットインタラプトイネーブル*/
			unsigned char RIE:1;		/*レシーブインタラプトイネーブル*/
			unsigned char TE:1;			/*トランスミットイネーブル*/
			unsigned char RE:1;			/*レシーブイネーブル*/
			unsigned char MPIE:1;		/*マルチプロセッサインタラプトイネーブル*/
			unsigned char TEIE:1;		/*トランスミットエンドインタラプトイネーブル*/
			unsigned char CKE:2;		/*クロックイネーブル*/
		} BIT;
	} SCR;
	unsigned char	TDR;				/*トランスミットデータレジスタ*/
	union								/*SSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TDRE:1;		/*トランスミットデータレジスタエンプティ*/
			unsigned char RDRF:1;		/*レシーブデータレジスタフル*/
			unsigned char ORER:1;		/*オーバーランエラー*/
			unsigned char FER:1;		/*フレーミングエラー、(注)スマートカードインタフェースではERSとなる*/
			unsigned char PER:1;		/*パリティエラー*/
			unsigned char TEND:1;		/*トランスミットエンド*/
			unsigned char MPB:1;		/*マルチプロセッサビット*/
			unsigned char MPBT:1;		/*マルチプロセッサビットトランスファ*/
		} BIT;
	} SSR;
	unsigned char	RDR;				/*レシーブデータレジスタ*/
	/* スマートカードインタフェース */
	union								/*SCMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*予約*/
			unsigned char SDIR:1;		/*スマートカードデータトランスファディレクション*/
			unsigned char SINV:1;		/*スマートカードデータインバート*/
			unsigned char rsv2:1;		/*予約*/
			unsigned char SMIF:1;		/*スマートカードインタフェースモードセレクト*/
		} BIT;
	} SCMR;
};
#define	SCI0	(*(volatile struct __SCI0_REG__ *)__SCI0_ADD__)	/* ビットフィールド用 */

struct __SCI1_REG__
{
	union								/*SMRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CA:1;			/*コミュニケーションモード、(注)スマートカードインタフェースではGMとなる*/
			unsigned char CHR:1;		/*キャラクタレングス*/
			unsigned char PE:1;			/*パリティイネーブル*/
			unsigned char OE:1;			/*パリティモード*/
			unsigned char STOP:1;		/*ストップビットレングス*/
			unsigned char MP:1;			/*マルチプロセッサモード*/
			unsigned char CKS:2;		/*クロックセレクト*/
		} BIT;
	} SMR;
	unsigned char	BRR;				/*ビットレートレジスタ*/
	union								/*SCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TIE:1;		/*トランスミットインタラプトイネーブル*/
			unsigned char RIE:1;		/*レシーブインタラプトイネーブル*/
			unsigned char TE:1;			/*トランスミットイネーブル*/
			unsigned char RE:1;			/*レシーブイネーブル*/
			unsigned char MPIE:1;		/*マルチプロセッサインタラプトイネーブル*/
			unsigned char TEIE:1;		/*トランスミットエンドインタラプトイネーブル*/
			unsigned char CKE:2;		/*クロックイネーブル*/
		} BIT;
	} SCR;
	unsigned char	TDR;				/*トランスミットデータレジスタ*/
	union								/*SSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TDRE:1;		/*トランスミットデータレジスタエンプティ*/
			unsigned char RDRF:1;		/*レシーブデータレジスタフル*/
			unsigned char ORER:1;		/*オーバーランエラー*/
			unsigned char FER:1;		/*フレーミングエラー、(注)スマートカードインタフェースではERSとなる*/
			unsigned char PER:1;		/*パリティエラー*/
			unsigned char TEND:1;		/*トランスミットエンド*/
			unsigned char MPB:1;		/*マルチプロセッサビット*/
			unsigned char MPBT:1;		/*マルチプロセッサビットトランスファ*/
		} BIT;
	} SSR;
	unsigned char	RDR;				/*レシーブデータレジスタ*/
};
#define	SCI1	(*(volatile struct __SCI1_REG__ *)__SCI1_ADD__)	/* ビットフィールド用 */

/* ADコンバーター */
struct __AD_REG__
{
	unsigned short	ADDRA;				/*ADDRAレジスタ*/
	unsigned short	ADDRB;				/*ADDRBレジスタ*/
	unsigned short	ADDRC;				/*ADDRCレジスタ*/
	unsigned short	ADDRD;				/*ADDRDレジスタ*/
	union								/*ADCSRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ADF:1;		/*A/Dエンドフラグ*/
			unsigned char ADIE:1;		/*A/Dインタラプトイネーブル*/
			unsigned char ADST:1;		/*A/Dスタート*/
			unsigned char SCAN:1;		/*スキャンモード*/
			unsigned char CKS:1;		/*クロックセレクト*/
			unsigned char CH:3;			/*チャネルセレクト*/
		} BIT;
	} ADCSR;
	union								/*ADCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TRGE:1;		/*トリガイネーブル*/
			unsigned char rsv1:7;		/*予約*/
		} BIT;
	} ADCR;
};
#define	AD		(*(volatile struct __AD_REG__ *)__AD_ADD__)	/* ビットフィールド用 */


/* DAコンバーター */
struct __DA_REG__
{
	union								/*DASTCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:7;		/*未使用*/
			unsigned char DASTE:1;		/*D/Aスタンバイイネーブル*/
		} BIT;
	} DASTCR;
	char	rsv[ 0xffffdc - 0xffff5c - 1 ];	/*空き*/
	unsigned char	DADR0;
	unsigned char	DADR1;
	union								/*DACRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DAOE1:1;		/*D/Aアウトプットイネーブル 1*/
			unsigned char DAOE0:1;		/*D/Aアウトプットイネーブル 0*/
			unsigned char DAE:1;		/*D/Aイネーブル*/
			unsigned char rsv1:5;		/*未使用*/
		} BIT;
	} DACR;
};
#define	DA		(*(volatile struct __DA_REG__ *)__DA_ADD__)	/* ビットフィールド用 */


/* ROM */
struct __FLASH_REG__
{
	union								/*FLMCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char VPP:1;		/*プログラム電圧*/
			unsigned char VPPE:1;		/*VPPイネーブルビット*/
			unsigned char rsv1:2;		/*予約*/
			unsigned char EV:1;			/*イレースベリファイモード*/
			unsigned char PV:1;			/*プログラムベリファイモード*/
			unsigned char E:1;			/*イレースモード*/
			unsigned char P:1;			/*プログラムモード*/
		} BIT;
	} FLMCR;
	char	rsv1;						/*空き*/
	union								/*EBR1レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char LB7:1;		/*ラージブロック 7*/
			unsigned char LB6:1;		/*ラージブロック 6*/
			unsigned char LB5:1;		/*ラージブロック 5*/
			unsigned char LB4:1;		/*ラージブロック 4*/
			unsigned char LB3:1;		/*ラージブロック 3*/
			unsigned char LB2:1;		/*ラージブロック 2*/
			unsigned char LB1:1;		/*ラージブロック 1*/
			unsigned char LB0:1;		/*ラージブロック 0*/
		} BIT;
	} EBR1;
	union								/*EBR2レジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char SB7:1;		/*消去ブロック指定レジスタ2 7*/
			unsigned char SB6:1;		/*消去ブロック指定レジスタ2 6*/
			unsigned char SB5:1;		/*消去ブロック指定レジスタ2 5*/
			unsigned char SB4:1;		/*消去ブロック指定レジスタ2 4*/
			unsigned char SB3:1;		/*消去ブロック指定レジスタ2 3*/
			unsigned char SB2:1;		/*消去ブロック指定レジスタ2 2*/
			unsigned char SB1:1;		/*消去ブロック指定レジスタ2 1*/
			unsigned char SB0:1;		/*消去ブロック指定レジスタ2 0*/
		} BIT;
	} EBR2;
	char	rsv2[ 0xffff48 - 0xffff43 - 1 ];	/*空き*/
	union								/*RAMCRレジスタ*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char FLER:1;		/*フラッシュメモリエラー*/
			unsigned char rsv1:3;		/*予約*/
			unsigned char RAMS:1;		/*RAMセレクト*/
			unsigned char RAM:3;		/*RAM*/
		} BIT;
	} RAMCR;
};
#define	FLASH	(*(volatile struct __DA_REG__ *)__FLASH_ADD__)	/* ビットフィールド用 */

union __DIVCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:6;		/*予約*/
		unsigned char DIV:2;		/*分周比*/
	} BIT;
};
#define	DIVCR	(*(volatile union __DIVCR_REG__ *)__DIVCR_ADD__)	/* ビットフィールド用 */

union __MSTCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char PSTOP:1;		/*システムクロックの出力をストップ*/
		unsigned char rsv1:1;		/*予約*/
		unsigned char _ITU:1;		/*ITU モジュールスタンバイ*/
		unsigned char _SCI0:1;		/*SCI0 モジュールスタンバイ*/
		unsigned char _SCI1:1;		/*SCI1 モジュールスタンバイ*/
		unsigned char _DMAC:1;		/*DMAC モジュールスタンバイ*/
		unsigned char _RFSHC:1;		/*RFSHC モジュールスタンバイ*/
		unsigned char _AD:1;		/*AD モジュールスタンバイ*/
	} BIT;
};
#define	MSTCR	(*(volatile union __MSTCR_REG__ *)__MSTCR_ADD__)	/* ビットフィールド用 */

#endif /* __PROJECT_HOS__H8_3048_H_ */
