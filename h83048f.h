/* ------------------------------------------------------------------------- */
/*  H8/3048F �p �w�b�_�t�@�C��                                               */
/*  �S�Ẵf�o�C�X�Ō��؂����Ă����ł͖����̂ŁA�g�p�ɂ������Ă͏\������   */
/*  ���K�v�ł��B                                                             */
/*  ���̕ӂ��l�̌��E�ƌ������ŁA�o�O�񍐑҂��Ă܂��B                       */
/*                                                                           */
/*  ��������w�b�_�[�t�@�C�� �o�[�W�����Q�Ƃ̈Ⴂ                            */
/*  �����̃w�b�_�[�t�@�C���ł�16bit���̃t�B�[���h�� int�ŕ\���Ă��܂��B      */
/*  ���̃w�b�_�[�t�@�C��������ɕ킨�����Ƃ��v���܂������Ashort�ŕ\������    */
/*  ���܂����B�ƌ����̂� SH�Ȃ񂩂����\ H8�ō쐬�����R�[�f�B���O���̂܂ܓ�   */
/*  �����Ⴄ���������̂ł���(���� SCI��)�A�Ⴆ�� AD�͂�͂�10bit�ł��̒���   */
/*  �� H8�� SH���ς�炸�A���W�X�^��16bit�ŃA�N�Z�X���܂��B�������� int��    */
/*  �������� short�ƂȂ�̂��C�}�C�`���Ȃ̂ŁA�����Ƃ�������ׂ� short�Ő�   */
/*  �����Ă��܂��B                                                           */
/*  �܂��A�����R���p�C���[ �o�[�W�����R�ȏ�ł͖��ƂȂ�Ȃ��r�b�g�t�B�[    */
/*  ���h�̏ȗ��ł����A�H���R���p�C���A�܂�����R���p�C�� �o�[�W�����Q��    */
/*  �T�u�Z�b�g�ł̓R���p�C���G���[�ƂȂ�̂ŁA�K���ȃt�B�[���h�����[�ĂĂ�   */
/*  �܂��B                                                                   */
/*                                                                           */
/*                                   Copyright (C) 1998-2002 by Project HOS  */
/* ------------------------------------------------------------------------- */


#ifndef __PROJECT_HOS__H8_3048_H_
#define __PROJECT_HOS__H8_3048_H_

/* IO �f�o�C�X�A�h���X��` */
#define	__DMAC0A_ADD__	0xffff20	/* DMAC0A���W�X�^�X�^�[�g�A�h���X */
#define	__DMAC0B_ADD__	0xffff28	/* DMAC0B���W�X�^�X�^�[�g�A�h���X */
#define	__DMAC1A_ADD__	0xffff30	/* DMAC1A���W�X�^�X�^�[�g�A�h���X */
#define	__DMAC1B_ADD__	0xffff38	/* DMAC1B���W�X�^�X�^�[�g�A�h���X */
#define	__DMAC0_ADD__	0xffff20	/* DMAC0���W�X�^�X�^�[�g�A�h���X */
#define	__DMAC1_ADD__	0xffff30	/* DMAC1���W�X�^�X�^�[�g�A�h���X */
#define	__FLASH_ADD__	0xffff40	/* FLASH���W�X�^�X�^�[�g�A�h���X */
#define	__DA_ADD__		0xffff5c	/* DA���W�X�^�X�^�[�g�A�h���X */
#define	__DIVCR_ADD__	0xffff5d	/* DIVCR���W�X�^�X�^�[�g�A�h���X */
#define	__MSTCR_ADD__	0xffff5e	/* MSTCR���W�X�^�X�^�[�g�A�h���X */
#define	__BSC_ADD__		0xffff5f	/* BSC���W�X�^�X�^�[�g�A�h���X */
#define	__ITU_COMM_ADD__	0xffff60	/* ITU���ʃ��W�X�^�X�^�[�g�A�h���X */
#define	__ITU0_ADD__	0xffff64	/* ITU0���W�X�^�X�^�[�g�A�h���X */
#define	__ITU1_ADD__	0xffff6e	/* ITU1���W�X�^�X�^�[�g�A�h���X */
#define	__ITU2_ADD__	0xffff78	/* ITU2���W�X�^�X�^�[�g�A�h���X */
#define	__ITU3_ADD__	0xffff82	/* ITU3���W�X�^�X�^�[�g�A�h���X */
#define	__ITU4_ADD__	0xffff92	/* ITU4���W�X�^�X�^�[�g�A�h���X */
#define	__TPC_ADD__		0xffffa0	/* TPC���W�X�^�X�^�[�g�A�h���X */
#define	__WDT_ADD__		0xffffa8	/* WDT���W�X�^�X�^�[�g�A�h���X */
#define	__RFSHC_ADD__	0xffffa8	/* RFSHC���W�X�^�X�^�[�g�A�h���X */
#define	__SCI0_ADD__	0xffffb0	/* SCI0���W�X�^�X�^�[�g�A�h���X */
#define	__SCI1_ADD__	0xffffb8	/* SCI1���W�X�^�X�^�[�g�A�h���X */
#define	__P1_ADD__		0xffffc0	/* PORT1���W�X�^�X�^�[�g�A�h���X */
#define	__P2_ADD__		0xffffc1	/* PORT2���W�X�^�X�^�[�g�A�h���X */
#define	__P3_ADD__		0xffffc4	/* PORT3���W�X�^�X�^�[�g�A�h���X */
#define	__P4_ADD__		0xffffc5	/* PORT4���W�X�^�X�^�[�g�A�h���X */
#define	__P5_ADD__		0xffffc8	/* PORT5���W�X�^�X�^�[�g�A�h���X */
#define	__P6_ADD__		0xffffc9	/* PORT6���W�X�^�X�^�[�g�A�h���X */
#define	__P8_ADD__		0xffffcd	/* PORT8���W�X�^�X�^�[�g�A�h���X */
#define	__P7_ADD__		0xffffce	/* PORT7���W�X�^�X�^�[�g�A�h���X */
#define	__P9_ADD__		0xffffd0	/* PORT9���W�X�^�X�^�[�g�A�h���X */
#define	__PA_ADD__		0xffffd1	/* PORT A���W�X�^�X�^�[�g�A�h���X */
#define	__PB_ADD__		0xffffd4	/* PORT B���W�X�^�X�^�[�g�A�h���X */
#define	__AD_ADD__		0xffffe0	/* AD���W�X�^�X�^�[�g�A�h���X */
#define	__MDCR_ADD__	0xfffff1	/* MDCR���W�X�^�X�^�[�g�A�h���X */
#define	__SYSCR_ADD__	0xfffff2	/* SYSCR���W�X�^�X�^�[�g�A�h���X */
#define	__INTC_ADD__	0xfffff4	/* INTC���W�X�^�X�^�[�g�A�h���X */


/* ���[�h�R���g���[�����W�X�^ */
union __MDCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:5;		/*�\��*/
		unsigned char MDS:3;		/*���[�h�Z���N�g*/
	} BIT;
};
#define	MDCR	(*(volatile union __MDCR_REG__ *)__MDCR_ADD__)	/* �r�b�g�t�B�[���h�p */

/* �V�X�e���R���g���[���[ */
union __SYSCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char SSBY:1;		/*�\�t�g�E�G�A�X�^���o�C*/
		unsigned char STS:3;		/*�X�^���o�C�^�C�}�Z���N�^*/
		unsigned char UE:1;			/*���[�U�[�r�b�g�C�l�[�u��*/
		unsigned char NMIEG:1;		/*NMI�G�b�W�Z���N�g*/
		unsigned char rsv1:1;		/*�\��*/
		unsigned char RAME:1;		/*RAM�C�l�[�u��*/
	} BIT;
};
#define	SYSCR	(*(volatile union __SYSCR_REG__ *)__SYSCR_ADD__)	/* �r�b�g�t�B�[���h�p */

/* �����݃R���g���[���[ */
struct __INTC_REG__
{
	union								/*ISCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*�\��*/
			unsigned char IRQ5SC:1;		/*IRQ�Z���X�R���g���[�� 5*/
			unsigned char IRQ4SC:1;		/*IRQ�Z���X�R���g���[�� 4*/
			unsigned char IRQ3SC:1;		/*IRQ�Z���X�R���g���[�� 3*/
			unsigned char IRQ2SC:1;		/*IRQ�Z���X�R���g���[�� 2*/
			unsigned char IRQ1SC:1;		/*IRQ�Z���X�R���g���[�� 1*/
			unsigned char IRQ0SC:1;		/*IRQ�Z���X�R���g���[�� 0*/
		} BIT;
	} ISCR;
	union								/*IER���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*�\��*/
			unsigned char IRQ5E:1;		/*IRQ�C�l�[�u�����W�X�^ 5*/
			unsigned char IRQ4E:1;		/*IRQ�C�l�[�u�����W�X�^ 4*/
			unsigned char IRQ3E:1;		/*IRQ�C�l�[�u�����W�X�^ 3*/
			unsigned char IRQ2E:1;		/*IRQ�C�l�[�u�����W�X�^ 2*/
			unsigned char IRQ1E:1;		/*IRQ�C�l�[�u�����W�X�^ 1*/
			unsigned char IRQ0E:1;		/*IRQ�C�l�[�u�����W�X�^ 0*/
		} BIT;
	} IER;
	union
	{								/*ISR���W�X�^*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*�\��*/
			unsigned char IRQ5F:1;		/*IRQ�X�e�[�^�X���W�X�^ 5*/
			unsigned char IRQ4F:1;		/*IRQ�X�e�[�^�X���W�X�^ 4*/
			unsigned char IRQ3F:1;		/*IRQ�X�e�[�^�X���W�X�^ 3*/
			unsigned char IRQ2F:1;		/*IRQ�X�e�[�^�X���W�X�^ 2*/
			unsigned char IRQ1F:1;		/*IRQ�X�e�[�^�X���W�X�^ 1*/
			unsigned char IRQ0F:1;		/*IRQ�X�e�[�^�X���W�X�^ 0*/
		} BIT;
	} ISR;
	char	rsv2;						/*��*/
	union								/*IPRA���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char _IRQ0:1;		/*IREQ0 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _IRQ1:1;		/*IREQ1 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _IRQ23:1;		/*IREQ23 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _IRQ45:1;		/*IREQ45 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _WDT:1;		/*WDT�A���t���b�V���R���g�����[�̊����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _ITU0:1;		/*ITU0 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _ITU1:1;		/*ITU1 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _ITU2:1;		/*ITU2 �����݂̃v���C�I���e�B���x���ݒ�*/
		} BIT;
	} IPRA;
	union
	{								/*IPRB���W�X�^*/
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char _ITU3:1;		/*ITU3 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _ITU4:1;		/*ITU4 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _DMAC:1;		/*DMAC0�A1 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char rsv1:1;		/*�\��*/
			unsigned char _SCI0:1;		/*SCI0 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _SCI1:1;		/*SCI1 �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char _AD:1;		/*AD �����݂̃v���C�I���e�B���x���ݒ�*/
			unsigned char rsv2:1;		/*�\��*/
		} BIT;
	} IPRB;
};
#define	INTC	(*(volatile struct __INTC_REG__ *)__INTC_ADD__)	/* �r�b�g�t�B�[���h�p */

/* �o�X�R���g���[���[ */
struct __BSC_REG__
{
	union								/*CSCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CS7E:1;		/*�`�b�v�Z���N�g�C�l�[�u�� 7*/
			unsigned char CS6E:1;		/*�`�b�v�Z���N�g�C�l�[�u�� 6*/
			unsigned char CS5E:1;		/*�`�b�v�Z���N�g�C�l�[�u�� 5*/
			unsigned char CS4E:1;		/*�`�b�v�Z���N�g�C�l�[�u�� 4*/
			unsigned char rsv1:4;		/*�\��*/
		} BIT;
	} CSCR;
	char	rsv1[ 0xffffec - 0xffff5f - 1 ];	/*��*/
	union								/*ABWCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ABW7:1;		/*�G���A �o�X�� �R���g���[�� 7*/
			unsigned char ABW6:1;		/*�G���A �o�X�� �R���g���[�� 6*/
			unsigned char ABW5:1;		/*�G���A �o�X�� �R���g���[�� 5*/
			unsigned char ABW4:1;		/*�G���A �o�X�� �R���g���[�� 4*/
			unsigned char ABW3:1;		/*�G���A �o�X�� �R���g���[�� 3*/
			unsigned char ABW2:1;		/*�G���A �o�X�� �R���g���[�� 2*/
			unsigned char ABW1:1;		/*�G���A �o�X�� �R���g���[�� 2*/
			unsigned char ABW0:1;		/*�G���A �o�X�� �R���g���[�� 0*/
		} BIT;
	} ABWCR;
	union								/*ASTCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char AST7:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 7*/
			unsigned char AST6:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 6*/
			unsigned char AST5:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 5*/
			unsigned char AST4:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 4*/
			unsigned char AST3:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 3*/
			unsigned char AST2:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 2*/
			unsigned char AST1:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 2*/
			unsigned char AST0:1;		/*�A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ 0*/
		} BIT;
	} ASTCR;
	union								/*WCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*�\��*/
			unsigned char WMS:2;		/*�E�G�C�g���[�h�Z���N�g*/
			unsigned char WC:2;			/*�E�G�C�g�J�E���g*/
		} BIT;
	} WCR;
	union								/*WCER���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char WCE7:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 7*/
			unsigned char WCE6:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 6*/
			unsigned char WCE5:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 5*/
			unsigned char WCE4:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 4*/
			unsigned char WCE3:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 3*/
			unsigned char WCE2:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 2*/
			unsigned char WCE1:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 2*/
			unsigned char WCE0:1;		/*�E�G�C�g�X�e�[�g�R���g���[���C�l�[�u�����W�X�^ 0*/
		} BIT;
	} WCER;
	char	rsv2[ 0xfffff3 - 0xffffef - 1 ];	/*��*/
	union								/*BRCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char A23E:1;		/*�A�h���X23 �C�l�[�u��*/
			unsigned char A22E:1;		/*�A�h���X22 �C�l�[�u��*/
			unsigned char A21E:1;		/*�A�h���X21 �C�l�[�u��*/
			unsigned char rsv1:4;		/*�\��*/
			unsigned char BRLE:1;		/*�o�X�����[�X�C�l�[�u��*/
		} BIT;
	} BRCR;
};
#define	BSC		(*(volatile struct __BSC_REG__ *)__BSC_ADD__)	/* �r�b�g�t�B�[���h�p */


/* ���t���b�V���R���g���[���[ */
struct __RFSHC_REG__
{
	union								/*RFSHCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char SRFMD:1;		/*�Z���t���t���b�V�����[�h*/
			unsigned char PSRAME:1;		/*PSRAM �C�l�[�u��*/
			unsigned char DRAME:1;		/*DRAM �C�l�[�u��*/
			unsigned char CASWE:1;		/*�X�g���[�u���[�h�Z���N�g*/
			unsigned char M9M8:1;		/*�A�h���X�}���`�v���b�N�X���[�h�Z���N�g*/
			unsigned char RFSHE:1;		/*���t���b�V���[�q�C�l�[�u���A�����̃w�b�_�[��PFSHE�ƂȂ��Ă���*/
			unsigned char rsv1:1;		/*�\��*/
			unsigned char RCYCE:1;		/*���t���b�V���T�C�N���C�l�[�u��*/
		} BIT;
	} RFSHCR;
	union								/*RTMCSR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CMF:1;		/*�R���y�A�}�b�`�t���O*/
			unsigned char CMIE:1;		/*�R���y�A�}�b�`�C���^���v�g�C�l�[�u��*/
			unsigned char CKS:3;		/*�N���b�N�Z���N�g*/
			unsigned char rsv1:3;		/*�\��*/
		} BIT;
	} RTMCSR;
	unsigned char	RTCNT;				/*���t���b�V���^�C�}�J�E���^*/
	unsigned char	RTCOR;				/*���t���b�V���^�C���R���X�^���g���W�X�^*/
};
#define	RFSHC	(*(volatile struct __RFSHC_REG__ *)__RFSHC_ADD__)	/* �r�b�g�t�B�[���h�p */


/* DMA�R���g���[���[ */
/* �V���[�g�A�h���X */
struct __DMAC_SHORT_REG__
{
	void	*MAR;						/*�������A�h���X���W�X�^*/
	unsigned short	ETCR;				/*�]���J�E���g���W�X�^*/
	unsigned char	IOAR;				/*I/O �A�h���X���W�X�^*/
	union								/*DTCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTE:1;		/*�f�[�^�g�����X�t�@�C�l�[�u��*/
			unsigned char DTSZ:1;		/*�f�[�^�g�����X�t�@�T�C�Y*/
			unsigned char DTID:1;		/*�f�[�^�g�����X�t�@�C���N�������g/�f�N�������g*/
			unsigned char RPE:1;		/*���s�[�g�C�l�[�u��*/
			unsigned char DTIE:1;		/*�f�[�^�g�����X�t�@�C���^���v�g�C�l�[�u��*/
			unsigned char DTS:3;		/*�f�[�^�g�����X�t�@�Z���N�g*/
		} BIT;
	} DTCR;
};
/* �t���A�h���X */
struct __DMAC_FULL_REG__
{
	void	*MARA;						/*�������A�h���X���W�X�^*/
	unsigned short	ETCRA;				/*�]���J�E���g���W�X�^*/
	char	rsv1;						/*��*/
	union								/*DTCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTE:1;		/*�f�[�^�g�����X�t�@�C�l�[�u��*/
			unsigned char DTSZ:1;		/*�f�[�^�g�����X�t�@�T�C�Y*/
			unsigned char SAID:1;		/*�\�[�X�A�h���X�C���N�������g/�f�N�������g*/
			unsigned char SAIDE:1;		/*�\�[�X�A�h���X�C���N�������g/�f�N�������g�C�l�[�u��*/
			unsigned char DTIE:1;		/*�f�[�^�g�����X�t�@�C���^���v�g�C�l�[�u��*/
			unsigned char DTS:3;		/*�f�[�^�g�����X�t�@�Z���N�g*/
		} BIT;
	} DTCRA;
	void	*MARB;						/*�������A�h���X���W�X�^*/
	unsigned short	ETCRB;				/*�]���J�E���g���W�X�^*/
	char	rsv2;						/*��*/
	union								/*DTCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DTME:1;		/*�f�[�^�g�����X�t�@�}�X�^�C�l�[�u��*/
			unsigned char rsv1:1;		/*�\��*/
			unsigned char DAID:1;		/*�f�B�X�e�B�l�[�V�����A�h���X�C���N�������g/�f�N�������g*/
			unsigned char DAIDE:1;		/*�f�B�X�e�B�l�[�V�����A�h���X�C���N�������g/�f�N�������g�C�l�[�u��*/
			unsigned char TMS:1;		/*�g�����X�t�@���[�h�Z���N�g*/
			unsigned char DTS:3;		/*�f�[�^�g�����X�t�@�Z���N�g*/
		} BIT;
	} DTCRB;
};
#define	DMAC0A	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC0A_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	DMAC0B	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC0B_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	DMAC1A	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC1A_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	DMAC1B	(*(volatile struct __DMAC_SHORT_REG__ *)__DMAC1B_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	DMAC0	(*(volatile struct __DMAC_FULL_REG__ *)__DMAC0_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	DMAC1	(*(volatile struct __DMAC_FULL_REG__ *)__DMAC1_ADD__)	/* �r�b�g�t�B�[���h�p */


/* IO�|�[�g */
/*DDR���W�X�^�ADR���W�X�^�͋��ʂŗ��p�ł���*/
struct __IO_PORT_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
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

#define	P1		(*(volatile struct __IO_PORT_REG__ *)__P1_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_2_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
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
	char rsv2[ 0xffffd8 - 0xffffc3 - 1 ];	/*��*/
	union								/*PCR���W�X�^*/
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
#define	P2		(*(volatile struct __IO_PORT_2_REG__ *)__P2_ADD__)	/* �r�b�g�t�B�[���h�p */

#define	P3		(*(volatile struct __IO_PORT_REG__ *)__P3_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_4_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
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
	char rsv2[ 0xffffda - 0xffffc7 - 1 ];	/*��*/
	union								/*PCR���W�X�^*/
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
#define	P4		(*(volatile struct __IO_PORT_4_REG__ *)__P4_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_5_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*�Y��bit����*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
	char rsv2[ 0xffffdb - 0xffffca - 1 ];	/*��*/
	union								/*PCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*�Y��bit����*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} PCR;
};
#define	P5		(*(volatile struct __IO_PORT_5_REG__ *)__P5_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_6_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*�Y��bit����*/
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
#define	P6		(*(volatile struct __IO_PORT_6_REG__ *)__P6_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_7_REG__
{
	union								/*DR���W�X�^*/
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
#define	P7		(*(volatile struct __IO_PORT_7_REG__ *)__P7_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_8_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*�Y��bit����*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};
#define	P8		(*(volatile struct __IO_PORT_8_REG__ *)__P8_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __IO_PORT_9_REG__
{
	unsigned char DDR;					/*DDR���W�X�^*/
	char rsv1;							/*��*/
	union								/*DR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*�Y��bit����*/
			unsigned char B5:1;			/*bit5*/
			unsigned char B4:1;			/*bit4*/
			unsigned char B3:1;			/*bit3*/
			unsigned char B2:1;			/*bit2*/
			unsigned char B1:1;			/*bit1*/
			unsigned char B0:1;			/*bit0*/
		} BIT;
	} DR;
};
#define	P9		(*(volatile struct __IO_PORT_9_REG__ *)__P9_ADD__)	/* �r�b�g�t�B�[���h�p */

#define	PA		(*(volatile struct __IO_PORT_REG__ *)__PA_ADD__)	/* �r�b�g�t�B�[���h�p */

#define	PB		(*(volatile struct __IO_PORT_REG__ *)__PB_ADD__)	/* �r�b�g�t�B�[���h�p */


/* ITU */
/*ITU���ʃ��W�X�^*/
struct __ITU_COMMON_REG__
{
	union								/*TSTR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*���g�p*/
			unsigned char STR4:1;		/*�J�E���^�X�^�[�g 4*/
			unsigned char STR3:1;		/*�J�E���^�X�^�[�g 3*/
			unsigned char STR2:1;		/*�J�E���^�X�^�[�g 2*/
			unsigned char STR1:1;		/*�J�E���^�X�^�[�g 1*/
			unsigned char STR0:1;		/*�J�E���^�X�^�[�g 0*/
		} BIT;
	} TSTR;
	union								/*TSNC���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*���g�p*/
			unsigned char SYNC4:1;		/*�^�C�}���� 4*/
			unsigned char SYNC3:1;		/*�^�C�}���� 3*/
			unsigned char SYNC2:1;		/*�^�C�}���� 2*/
			unsigned char SYNC1:1;		/*�^�C�}���� 1*/
			unsigned char SYNC0:1;		/*�^�C�}���� 0*/
		} BIT;
	} TSNC;
	union								/*TMDR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*���g�p*/
			unsigned char MDF:1;		/*�ʑ��W�����[�h*/
			unsigned char FDIR:1;		/*�t���O�f�B���N�V����*/
			unsigned char PWM4:1;		/*PWM���[�h 4*/
			unsigned char PWM3:1;		/*PWM���[�h 3*/
			unsigned char PWM2:1;		/*PWM���[�h 2*/
			unsigned char PWM1:1;		/*PWM���[�h 1*/
			unsigned char PWM0:1;		/*PWM���[�h 0*/
		} BIT;
	} TMDR;
	union								/*TFCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*���g�p*/
			unsigned char CMD:2;		/*�R���r�l�[�V�������[�h 1*/
			unsigned char BFB4:1;		/*�o�b�t�@���� B4*/
			unsigned char BFA4:1;		/*�o�b�t�@���� A4*/
			unsigned char BFB3:1;		/*�o�b�t�@���� B3*/
			unsigned char BFA3:1;		/*�o�b�t�@���� A3*/
		} BIT;
	} TFCR;
	char	rsv[ 0xffff90 - 0xffff63 - 1 ];	/*��*/
	union								/*TOER���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:2;		/*���g�p*/
			unsigned char EXB4:1;		/*�}�X�^�[�C�l�[�u�� TOCXB4*/
			unsigned char EXA4:1;		/*�}�X�^�[�C�l�[�u�� TOCXA4*/
			unsigned char EB3:1;		/*�}�X�^�[�C�l�[�u�� TIOCB3*/
			unsigned char EB4:1;		/*�}�X�^�[�C�l�[�u�� TIOCB4*/
			unsigned char EA4:1;		/*�}�X�^�[�C�l�[�u�� TIOCA4*/
			unsigned char EA3:1;		/*�}�X�^�[�C�l�[�u�� TIOCA3*/
		} BIT;
	} TOER;
	union								/*TOCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:3;		/*���g�p*/
			unsigned char XTGD:1;		/*�O���g���K�f�B�X�G�[�u��*/
			unsigned char rsv2:2;		/*���g�p*/
			unsigned char OLS4:1;		/*�o�̓��x���Z���N�g 4*/
			unsigned char OLS3:1;		/*�o�̓��x���Z���N�g 3*/
		} BIT;
	} TOCR;
};

#define	ITU		(*(volatile struct __ITU_COMMON_REG__ *)__ITU_COMM_ADD__)	/* �r�b�g�t�B�[���h�p */

/*ITU�ʃ��W�X�^*/
struct __ITU_TYPE0_REG__
{
	union								/*TCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*���g�p*/
			unsigned char CCLR:2;		/*�J�E���^�N���A*/
			unsigned char CKEG:2;		/*�N���b�N�G�b�W*/
			unsigned char TPSC:3;		/*�^�C�}�v���X�P�[��*/
		} BIT;
	} TCR;
	union								/*TIOR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*���g�p*/
			unsigned char IOB:3;		/*I/O �R���g���[��*/
			unsigned char rsv2:1;		/*���g�p*/
			unsigned char IOA:3;		/*I/O �R���g���[��*/
		} BIT;
	} TIOR;
	union								/*TIER���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*���g�p*/
			unsigned char OVIE:1;		/*�I�[�o�[�t���[�C���^���v�g�C�l�[�u��*/
			unsigned char IMIEB:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�C���^���v�g�C�l�[�u�� B*/
			unsigned char IMIEA:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�C���^���v�g�C�l�[�u�� A*/
		} BIT;
	} TIER;
	union								/*TSR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*���g�p*/
			unsigned char OVF:1;		/*�I�[�o�[�t���[�t���O*/
			unsigned char IMFB:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�t���O B*/
			unsigned char IMFA:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�t���O A*/
		} BIT;
	} TSR;
	unsigned short	TCNT;				/*16bit �^�C�}�J�E���^*/
	unsigned short	GRA;				/*�W�F�l�������W�X�^ A*/
	unsigned short	GRB;				/*�W�F�l�������W�X�^ B*/
};

struct __ITU_TYPE3_REG__
{
	union								/*TCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*���g�p*/
			unsigned char CCLR:2;		/*�J�E���^�N���A*/
			unsigned char CKEG:2;		/*�N���b�N�G�b�W*/
			unsigned char TPSC:3;		/*�^�C�}�v���X�P�[��*/
		} BIT;
	} TCR;
	union								/*TIOR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:1;		/*���g�p*/
			unsigned char IOB:3;		/*I/O �R���g���[��*/
			unsigned char rsv2:1;		/*���g�p*/
			unsigned char IOA:3;		/*I/O �R���g���[��*/
		} BIT;
	} TIOR;
	union								/*TIER���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*���g�p*/
			unsigned char OVIE:1;		/*�I�[�o�[�t���[�C���^���v�g�C�l�[�u��*/
			unsigned char IMIEB:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�C���^���v�g�C�l�[�u�� B*/
			unsigned char IMIEA:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�C���^���v�g�C�l�[�u�� A*/
		} BIT;
	} TIER;
	union								/*TSR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:5;		/*���g�p*/
			unsigned char OVF:1;		/*�I�[�o�[�t���[�t���O*/
			unsigned char IMFB:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�t���O B*/
			unsigned char IMFA:1;		/*�C���v�b�g�L���v�`��/�R���y�A�}�b�`�t���O A*/
		} BIT;
	} TSR;
	unsigned short	TCNT;				/*16bit �^�C�}�J�E���^*/
	unsigned short	GRA;				/*�W�F�l�������W�X�^ A*/
	unsigned short	GRB;				/*�W�F�l�������W�X�^ B*/
	unsigned short	BRA;				/*�o�b�t�@���W�X�^ A*/
	unsigned short	BRB;				/*�o�b�t�@���W�X�^ B*/
};

#define	ITU0	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU0_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	ITU1	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU1_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	ITU2	(*(volatile struct __ITU_TYPE0_REG__ *)__ITU2_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	ITU3	(*(volatile struct __ITU_TYPE3_REG__ *)__ITU3_ADD__)	/* �r�b�g�t�B�[���h�p */
#define	ITU4	(*(volatile struct __ITU_TYPE3_REG__ *)__ITU4_ADD__)	/* �r�b�g�t�B�[���h�p */


/* �v���O���}�u���^�C�~���O�p�^�[���R���g���[���[ */
struct __TPC_REG__
{
	union								/*TPMR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*���g�p*/
			unsigned char G3NOV:1;		/*�O���[�v 3 �m���I�[�o�[���b�v*/
			unsigned char G2NOV:1;		/*�O���[�v 2 �m���I�[�o�[���b�v*/
			unsigned char G1NOV:1;		/*�O���[�v 1 �m���I�[�o�[���b�v*/
			unsigned char G0NOV:1;		/*�O���[�v 0 �m���I�[�o�[���b�v*/
		} BIT;
	} TPMR;
	union								/*TPCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char G3CMS:2;		/*�O���[�v 3 �R���y�A�}�b�`�Z���N�g*/
			unsigned char G2CMS:2;		/*�O���[�v 2 �R���y�A�}�b�`�Z���N�g*/
			unsigned char G1CMS:2;		/*�O���[�v 1 �R���y�A�}�b�`�Z���N�g*/
			unsigned char G0CMS:2;		/*�O���[�v 0 �R���y�A�}�b�`�Z���N�g*/
		} BIT;
	} TPCR;
	union								/*NDERB���W�X�^*/
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
	union								/*NDERA���W�X�^*/
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
	union								/*NDRB1���W�X�^*/
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
	union								/*NDRA1���W�X�^*/
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
	union								/*NDRB2���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*���g�p*/
			unsigned char B11:1;		/*bit 11*/
			unsigned char B10:1;		/*bit 10*/
			unsigned char B9:1;			/*bit 9*/
			unsigned char B8:1;			/*bit 8*/
		} BIT;
	} NDRB2;
	union								/*NDRA2���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*���g�p*/
			unsigned char B3:1;			/*bit 3*/
			unsigned char B2:1;			/*bit 2*/
			unsigned char B1:1;			/*bit 1*/
			unsigned char B0:1;			/*bit 0*/
		} BIT;
	} NDRA2;
};
#define	TPC	(*(volatile struct __TPC_REG__ *)__TPC_ADD__)	/* �r�b�g�t�B�[���h�p */


/* �E�I�b�`�h�b�O�^�C�}�[ */
union __WDT_REG__
{
	/*�ǂݍ��ݐ�p*/
	struct
	{
		union								/*DTSCR���W�X�^*/
		{
			unsigned char BYTE;				/*Byte Access*/
			struct
			{
				unsigned char OVF:1;		/*�I�[�o�[�t���[�t���O*/
				unsigned char WTIT:1;		/*�^�C�}���[�h�Z���N�g*/
				unsigned char TME:1;		/*�^�C�}�C�l�[�u��*/
				unsigned char rsv1:2;		/*�\��*/
				unsigned char CKS:3;		/*�N���b�N�Z���N�g*/
			} BIT;
		} TSCR;
		unsigned char	TCNT;				/*TCNT���W�X�^*/
		char	rsv1;						/*��*/
		union								/*RSTCSR���W�X�^*/
		{
			unsigned char BYTE;				/*Byte Access*/
			struct
			{
				unsigned char WRST:1;		/*�E�I�b�`�h�b�O�^�C�}���Z�b�g*/
				unsigned char RSTOE:1;		/*���Z�b�g�o�̓C�l�[�u��*/
				unsigned char rsv1:6;		/*�\��*/
			} BIT;
		} RSTCSR;
	} READ;
	/*�������ݐ�p*/
	struct
	{
		unsigned short	TSCR;
		unsigned short	RSTCSR;
	} WRITE;
};
#define	WDT		(*(volatile union __WDT_REG__ *)__WDT_ADD__)	/* �r�b�g�t�B�[���h�p */


/* �V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X */
struct __SCI0_REG__
{
	union								/*SMR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CA:1;			/*�R�~���j�P�[�V�������[�h�A(��)�X�}�[�g�J�[�h�C���^�t�F�[�X�ł�GM�ƂȂ�*/
			unsigned char CHR:1;		/*�L�����N�^�����O�X*/
			unsigned char PE:1;			/*�p���e�B�C�l�[�u��*/
			unsigned char OE:1;			/*�p���e�B���[�h*/
			unsigned char STOP:1;		/*�X�g�b�v�r�b�g�����O�X*/
			unsigned char MP:1;			/*�}���`�v���Z�b�T���[�h*/
			unsigned char CKS:2;		/*�N���b�N�Z���N�g*/
		} BIT;
	} SMR;
	unsigned char	BRR;				/*�r�b�g���[�g���W�X�^*/
	union								/*SCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TIE:1;		/*�g�����X�~�b�g�C���^���v�g�C�l�[�u��*/
			unsigned char RIE:1;		/*���V�[�u�C���^���v�g�C�l�[�u��*/
			unsigned char TE:1;			/*�g�����X�~�b�g�C�l�[�u��*/
			unsigned char RE:1;			/*���V�[�u�C�l�[�u��*/
			unsigned char MPIE:1;		/*�}���`�v���Z�b�T�C���^���v�g�C�l�[�u��*/
			unsigned char TEIE:1;		/*�g�����X�~�b�g�G���h�C���^���v�g�C�l�[�u��*/
			unsigned char CKE:2;		/*�N���b�N�C�l�[�u��*/
		} BIT;
	} SCR;
	unsigned char	TDR;				/*�g�����X�~�b�g�f�[�^���W�X�^*/
	union								/*SSR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TDRE:1;		/*�g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B*/
			unsigned char RDRF:1;		/*���V�[�u�f�[�^���W�X�^�t��*/
			unsigned char ORER:1;		/*�I�[�o�[�����G���[*/
			unsigned char FER:1;		/*�t���[�~���O�G���[�A(��)�X�}�[�g�J�[�h�C���^�t�F�[�X�ł�ERS�ƂȂ�*/
			unsigned char PER:1;		/*�p���e�B�G���[*/
			unsigned char TEND:1;		/*�g�����X�~�b�g�G���h*/
			unsigned char MPB:1;		/*�}���`�v���Z�b�T�r�b�g*/
			unsigned char MPBT:1;		/*�}���`�v���Z�b�T�r�b�g�g�����X�t�@*/
		} BIT;
	} SSR;
	unsigned char	RDR;				/*���V�[�u�f�[�^���W�X�^*/
	/* �X�}�[�g�J�[�h�C���^�t�F�[�X */
	union								/*SCMR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:4;		/*�\��*/
			unsigned char SDIR:1;		/*�X�}�[�g�J�[�h�f�[�^�g�����X�t�@�f�B���N�V����*/
			unsigned char SINV:1;		/*�X�}�[�g�J�[�h�f�[�^�C���o�[�g*/
			unsigned char rsv2:1;		/*�\��*/
			unsigned char SMIF:1;		/*�X�}�[�g�J�[�h�C���^�t�F�[�X���[�h�Z���N�g*/
		} BIT;
	} SCMR;
};
#define	SCI0	(*(volatile struct __SCI0_REG__ *)__SCI0_ADD__)	/* �r�b�g�t�B�[���h�p */

struct __SCI1_REG__
{
	union								/*SMR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char CA:1;			/*�R�~���j�P�[�V�������[�h�A(��)�X�}�[�g�J�[�h�C���^�t�F�[�X�ł�GM�ƂȂ�*/
			unsigned char CHR:1;		/*�L�����N�^�����O�X*/
			unsigned char PE:1;			/*�p���e�B�C�l�[�u��*/
			unsigned char OE:1;			/*�p���e�B���[�h*/
			unsigned char STOP:1;		/*�X�g�b�v�r�b�g�����O�X*/
			unsigned char MP:1;			/*�}���`�v���Z�b�T���[�h*/
			unsigned char CKS:2;		/*�N���b�N�Z���N�g*/
		} BIT;
	} SMR;
	unsigned char	BRR;				/*�r�b�g���[�g���W�X�^*/
	union								/*SCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TIE:1;		/*�g�����X�~�b�g�C���^���v�g�C�l�[�u��*/
			unsigned char RIE:1;		/*���V�[�u�C���^���v�g�C�l�[�u��*/
			unsigned char TE:1;			/*�g�����X�~�b�g�C�l�[�u��*/
			unsigned char RE:1;			/*���V�[�u�C�l�[�u��*/
			unsigned char MPIE:1;		/*�}���`�v���Z�b�T�C���^���v�g�C�l�[�u��*/
			unsigned char TEIE:1;		/*�g�����X�~�b�g�G���h�C���^���v�g�C�l�[�u��*/
			unsigned char CKE:2;		/*�N���b�N�C�l�[�u��*/
		} BIT;
	} SCR;
	unsigned char	TDR;				/*�g�����X�~�b�g�f�[�^���W�X�^*/
	union								/*SSR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TDRE:1;		/*�g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B*/
			unsigned char RDRF:1;		/*���V�[�u�f�[�^���W�X�^�t��*/
			unsigned char ORER:1;		/*�I�[�o�[�����G���[*/
			unsigned char FER:1;		/*�t���[�~���O�G���[�A(��)�X�}�[�g�J�[�h�C���^�t�F�[�X�ł�ERS�ƂȂ�*/
			unsigned char PER:1;		/*�p���e�B�G���[*/
			unsigned char TEND:1;		/*�g�����X�~�b�g�G���h*/
			unsigned char MPB:1;		/*�}���`�v���Z�b�T�r�b�g*/
			unsigned char MPBT:1;		/*�}���`�v���Z�b�T�r�b�g�g�����X�t�@*/
		} BIT;
	} SSR;
	unsigned char	RDR;				/*���V�[�u�f�[�^���W�X�^*/
};
#define	SCI1	(*(volatile struct __SCI1_REG__ *)__SCI1_ADD__)	/* �r�b�g�t�B�[���h�p */

/* AD�R���o�[�^�[ */
struct __AD_REG__
{
	unsigned short	ADDRA;				/*ADDRA���W�X�^*/
	unsigned short	ADDRB;				/*ADDRB���W�X�^*/
	unsigned short	ADDRC;				/*ADDRC���W�X�^*/
	unsigned short	ADDRD;				/*ADDRD���W�X�^*/
	union								/*ADCSR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char ADF:1;		/*A/D�G���h�t���O*/
			unsigned char ADIE:1;		/*A/D�C���^���v�g�C�l�[�u��*/
			unsigned char ADST:1;		/*A/D�X�^�[�g*/
			unsigned char SCAN:1;		/*�X�L�������[�h*/
			unsigned char CKS:1;		/*�N���b�N�Z���N�g*/
			unsigned char CH:3;			/*�`���l���Z���N�g*/
		} BIT;
	} ADCSR;
	union								/*ADCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char TRGE:1;		/*�g���K�C�l�[�u��*/
			unsigned char rsv1:7;		/*�\��*/
		} BIT;
	} ADCR;
};
#define	AD		(*(volatile struct __AD_REG__ *)__AD_ADD__)	/* �r�b�g�t�B�[���h�p */


/* DA�R���o�[�^�[ */
struct __DA_REG__
{
	union								/*DASTCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char rsv1:7;		/*���g�p*/
			unsigned char DASTE:1;		/*D/A�X�^���o�C�C�l�[�u��*/
		} BIT;
	} DASTCR;
	char	rsv[ 0xffffdc - 0xffff5c - 1 ];	/*��*/
	unsigned char	DADR0;
	unsigned char	DADR1;
	union								/*DACR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char DAOE1:1;		/*D/A�A�E�g�v�b�g�C�l�[�u�� 1*/
			unsigned char DAOE0:1;		/*D/A�A�E�g�v�b�g�C�l�[�u�� 0*/
			unsigned char DAE:1;		/*D/A�C�l�[�u��*/
			unsigned char rsv1:5;		/*���g�p*/
		} BIT;
	} DACR;
};
#define	DA		(*(volatile struct __DA_REG__ *)__DA_ADD__)	/* �r�b�g�t�B�[���h�p */


/* ROM */
struct __FLASH_REG__
{
	union								/*FLMCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char VPP:1;		/*�v���O�����d��*/
			unsigned char VPPE:1;		/*VPP�C�l�[�u���r�b�g*/
			unsigned char rsv1:2;		/*�\��*/
			unsigned char EV:1;			/*�C���[�X�x���t�@�C���[�h*/
			unsigned char PV:1;			/*�v���O�����x���t�@�C���[�h*/
			unsigned char E:1;			/*�C���[�X���[�h*/
			unsigned char P:1;			/*�v���O�������[�h*/
		} BIT;
	} FLMCR;
	char	rsv1;						/*��*/
	union								/*EBR1���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char LB7:1;		/*���[�W�u���b�N 7*/
			unsigned char LB6:1;		/*���[�W�u���b�N 6*/
			unsigned char LB5:1;		/*���[�W�u���b�N 5*/
			unsigned char LB4:1;		/*���[�W�u���b�N 4*/
			unsigned char LB3:1;		/*���[�W�u���b�N 3*/
			unsigned char LB2:1;		/*���[�W�u���b�N 2*/
			unsigned char LB1:1;		/*���[�W�u���b�N 1*/
			unsigned char LB0:1;		/*���[�W�u���b�N 0*/
		} BIT;
	} EBR1;
	union								/*EBR2���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char SB7:1;		/*�����u���b�N�w�背�W�X�^2 7*/
			unsigned char SB6:1;		/*�����u���b�N�w�背�W�X�^2 6*/
			unsigned char SB5:1;		/*�����u���b�N�w�背�W�X�^2 5*/
			unsigned char SB4:1;		/*�����u���b�N�w�背�W�X�^2 4*/
			unsigned char SB3:1;		/*�����u���b�N�w�背�W�X�^2 3*/
			unsigned char SB2:1;		/*�����u���b�N�w�背�W�X�^2 2*/
			unsigned char SB1:1;		/*�����u���b�N�w�背�W�X�^2 1*/
			unsigned char SB0:1;		/*�����u���b�N�w�背�W�X�^2 0*/
		} BIT;
	} EBR2;
	char	rsv2[ 0xffff48 - 0xffff43 - 1 ];	/*��*/
	union								/*RAMCR���W�X�^*/
	{
		unsigned char BYTE;				/*Byte Access*/
		struct
		{
			unsigned char FLER:1;		/*�t���b�V���������G���[*/
			unsigned char rsv1:3;		/*�\��*/
			unsigned char RAMS:1;		/*RAM�Z���N�g*/
			unsigned char RAM:3;		/*RAM*/
		} BIT;
	} RAMCR;
};
#define	FLASH	(*(volatile struct __DA_REG__ *)__FLASH_ADD__)	/* �r�b�g�t�B�[���h�p */

union __DIVCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char rsv1:6;		/*�\��*/
		unsigned char DIV:2;		/*������*/
	} BIT;
};
#define	DIVCR	(*(volatile union __DIVCR_REG__ *)__DIVCR_ADD__)	/* �r�b�g�t�B�[���h�p */

union __MSTCR_REG__
{
	unsigned char BYTE;				/*Byte Access*/
	struct
	{
		unsigned char PSTOP:1;		/*�V�X�e���N���b�N�̏o�͂��X�g�b�v*/
		unsigned char rsv1:1;		/*�\��*/
		unsigned char _ITU:1;		/*ITU ���W���[���X�^���o�C*/
		unsigned char _SCI0:1;		/*SCI0 ���W���[���X�^���o�C*/
		unsigned char _SCI1:1;		/*SCI1 ���W���[���X�^���o�C*/
		unsigned char _DMAC:1;		/*DMAC ���W���[���X�^���o�C*/
		unsigned char _RFSHC:1;		/*RFSHC ���W���[���X�^���o�C*/
		unsigned char _AD:1;		/*AD ���W���[���X�^���o�C*/
	} BIT;
};
#define	MSTCR	(*(volatile union __MSTCR_REG__ *)__MSTCR_ADD__)	/* �r�b�g�t�B�[���h�p */

#endif /* __PROJECT_HOS__H8_3048_H_ */
