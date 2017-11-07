/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:		hpStructDef.h
 Description:
				define plc struct data.
				
 Author:		Shane(xianjingxiong)
 Create Date:	2013-01-28 14:39
 History:
 ---------------------------------------------------------------------
 ID		Date			Author			Description
 01,	2013-01-28		Shane			create file
 
**********************************************************************/
#ifndef HP_STRUCT_DEF_H
#define HP_STRUCT_DEF_H
#include "plcApi.h"

#ifndef MAC_ADDR_LEN
#define MAC_ADDR_LEN 6
#endif

#ifndef HP_NID_LEN
#define HP_NID_LEN 	7
#endif


#define HP_QCA_MTYPE	0x88E1
#define HP_BCM_MTYPE 	0x8912
#define HP_QCA_MMV	0x00
#define HP_QCA_MMV1	0x01
#define HP_BCM_MMV	0x02

#define HP_NTW_NAME_MAX_LEN			24
#define HP_NTW_NAME_MIN_LEN			4
#define HP_DEV_PWD_MAX_LEN			24
#define HP_DEV_PWD_MIN_LEN			4
#define HP_NMK_LEN					16
#define HP_DAK_LEN					16
#define HP_MAX_RMT_STA_NUM			32
//#define HP_PIB_BUFFER_SIZE		0x5196			/* 20888, a larger buffer for 7500 add by puhaowen, 2015-6-3*/
#define HP_PIB_BUFFER_SIZE		0x8000			/* extend to 32KB, by puhaowen, 2016-7-3*/
#define HP_SW_VERSION_LEN			128
#define HP_DEV_NAME_MAX_LEN		16				/* add by shane, max length of device name */

#define MIN_HP_ETH_FRAME_LEN		60
#define MAX_HP_ETH_FRAME_LEN		1514	

#define MIN_HP_PACKET_SIZE			MIN_HP_ETH_FRAME_LEN
#define MAX_HP_PACKET_SIZE			MAX_HP_ETH_FRAME_LEN

#define MAX_HP_VS_MOD_DATA_LEN		1024		/* used for VS_XX_MOD, max length of Module data in a packet */
#define MAX_HP_VS_MOD_OPER_DATA_LEN	1400		/* used for VS_MOD_OPER, max length of Module data in a packet */
#define MAX_BCM_PARAM_LEN	1400 /*careful not determined*/


/*add by wanxiangjun*/
typedef PLC_DEV_TYPE HP_DEV_TYPE_T;

typedef enum
{
	HP_LED_STATE_OFF = 0,
	HP_LED_STATE_ON,
	HP_LED_STATE_ERROR,
}HP_LED_STATE_T;

typedef enum
{
	HP_UPG_TYPE_FIRMWARE = 0, //firmwave upgrade
	HP_UPG_TYPE_PARAM_CONFIG, //configuration parameters upgrade
	HP_UPG_TYPE_BOOT_HEADER, //boot header upgrade
	HP_UPG_TYPE_BIN, //binary
	HP_UPG_TYPE_RACFG,
	HP_UPG_TYPE_RABIN,
	HP_UPG_TYPE_SMALL_FIRMWARE,
	HP_UPG_TYPE_TR069_FIRMWARE,
	HP_UPG_TYPE_TR069_PARMCONFIG,
	HP_UPG_TYPE_TR069_SSLCFG,
	HP_UPG_TYPE_TR069_PARAMCONFIGB,
	HP_UPG_TYPE_TR069_SSLCPE,
	HP_UPG_TYPE_RAW,
	HP_UPG_TYPE_NULL_FIRMWARE,
	HP_UPG_TYPE_PCFG,
	HP_UPG_TYPE_ERR,
}HP_UPG_TYPE_T;

/*end*/
	

/* Define the device ID */
enum
{
        eINT6000Device  = 0x01,
        eINT6300Device  = 0x02,
        eINT6400Device  = 0x03,
        eINT7400Device  = 0x04,
        eAR6405Device   = 0x05,
        eAR7450Device   = 0x06,
        eAR7420Device   = 0x20,
        eQCA6410Device  = 0x21,
        eAR7500Device   = 0x30,
};

enum
{
	eBCM60500Device = 0x4E,
	eBCM60333Device = 0x4F,
	eBCM60335Device = 0x5A,
};


enum
{
	eMODOP_RDMEM 			= 0x00,
	eMODOP_RDNVM 			= 0x01,
	eMODOP_WRSESSION 	= 0x10,
	eMODOP_WRMOD 		= 0x11,
	eMODOP_CMNVM 			= 0x12,

	eMODOP_NOTUSE		= 0xff,
};

/* PLC hostActionReq type */
enum
{
	eHST_IND_FW     = 0x00,
	eHST_IND_UPDATE = 0x02,
	eHST_IND_MCTL   = 0x04,
	eHST_IND_FAC    = 0x05,
};


/*add by wanxiangjun*/
#define HP_APL2C_DISCOVERY			0xa070
#define HP_APCM_SET_KEY				0xa018
#define HP_APFW_GET_PARAM			0xa05c
#define HP_APFW_SET_PARAM			0xa058
#define HP_APFW_GET_DEBUG			0xa060
#define HP_APCM_NW_STATS			0xa02c
#define HP_APFW_FACTORY_RESET		0xa054
#define HP_APCM_STA_RESTART			0xa020
#define HP_APSTA_INFO				0xa04c
#define HP_APCM_AUTHORIZE			0xa010
#define HP_APFW_UPGRADE				0xa050
#define HP_APCM_UKE_CMD				0xa08c
#define HP_APFW_HDR_CFG_PARM_GET	0xA078
#define HP_APFW_HDR_CFG_PARM_SET	0xA07C



/*---------------PLC Specific Management Message Types---------------*/
#define HP_VS_SW_VER				0xA000
#define HP_VS_WR_MEM				0xA004
#define HP_VS_RD_MEM				0xA008
#define HP_VS_ST_MAC				0xA00C
#define HP_VS_GET_NVM				0xA010
#define HP_VS_RSVD_1				0xA014
#define HP_VS_RSVD_2				0xA018
#define HP_VS_RS_DEV				0xA01C
#define HP_VS_WR_MOD				0xA020
#define HP_VS_RD_MOD				0xA024
#define HP_VS_MOD_NVM				0xA028
#define HP_VS_WD_RPT				0xA02C
#define HP_VS_LNK_STATS				0xA030
#define HP_VS_SNIFFER				0xA034
#define HP_VS_NW_INFO				0xA038
#define HP_VS_RSVD_3				0xA03C
#define HP_VS_CP_RPT				0xA040
#define HP_VS_RSVD_4				0xA044
#define HP_VS_FR_LBK				0xA048
#define HP_VS_LBK_STAT				0xA04C
#define HP_VS_SET_KEY				0xA050
#define HP_VS_MFG_STRING			0xA054
#define HP_VS_RD_CBLOCK				0xA058
#define HP_VS_SET_SDRAM				0xA05C
#define HP_VS_HST_ACTION			0xA060
#define HP_VS_RSVD_5				0xA064
#define HP_VS_OP_ATTRIBUTES			0xA068
#define HP_VS_ENET_SETTINGS			0xA06C
#define HP_VS_TONE_MAP_CHAR			0xA070
#define HP_VS_NW_INFO_STATS			0xA074
#define HP_VS_FAC_DEFAULTS			0xA07C
#define HP_VS_PTS_NVM               		0xA080
#define HP_VS_RX_TONE_MAP_CHAR			0xA090
#define HP_VS_SET_LED_BEHAVIOR			0xA094
#define HP_VS_WRITE_AND_EXECUTE_APPLET	0XA098
#define HP_VS_MDIO_COMMAND			0XA09C
#define HP_VS_MOD_OPER				0xA0B0
#define HP_VS_PAIR				0x8000
#define HP_VS_STATE_CHANGE_INDICATE		0xA0BE
#define HP_VS_MISTERY				0xA148	/* Can not find in doc, used to write protected info to factory pib*/



#define HP_MMTYPE_REQ 				0x0000
#define HP_MMTYPE_CNF 				0x0001
#define HP_MMTYPE_IND 				0x0002
#define HP_MMTYPE_RSP 				0x0003

/* Added by SongWei, for lc chip support */
#define HP_AV_LC_MODULE_ID_NVM			0x7001
#define HP_AV_LC_MODULE_ID_PIB			0x7002

/* End Added */

/*-----------------------------Module ID-----------------------------*/
#define HP_MACSL_MODID				0x00
#define HP_MACSW_MODID				0x01
#define HP_PIB_MODID				0x02
#define HP_MACSWPIB_MODID			0x03
#define HP_WRALT_MODID				0x10

/*add by wanxiangjun*/
#define QCA_HEADER_LEN 20
#define BCM_HEADER_LEN 23
#define HP_MAX_HFID_LEN 64
#define HP_MAX_SW_VER_LEN 128
#define HP_MAX_FILES_UPGRADE 10
#define HP_UPG_FILE_NAME_MAX_LEN 	50

#define BCM_PARAM_QOS 				0x0069
#define BCM_PARAM_MANUFACTURER_NID	0x0007
#define BCM_PARAM_MANUFACTURER_NMK	0x0008
#define BCM_PARAM_NID				0x0023
#define BCM_PARAM_NMK				0x0024
#define BCM_PARAM_USER_HFID			0x0025
#define BCM_PARAM_MANUFACTURE_HFID	0x001B
#define BCM_PARAM_CONTROL_LED			0x003e
#define BCM_PARAM_OPTION_LED			0x003f
#define BCM_PARAM_DAK1				0x0009
#define BCM_PARAM_TX_MODE			0x0055
#define BCM_PARAM_POWERSAVE			0x0029

/*end*/

/* for plc recover, add by puhaowen */
/*------------------------------NVM information------------------------------*/
/* image tye attached to header in nvm chain, refer to ImageType */
#define NVM_IMAGE_GENERIC           0x0000
#define NVM_IMAGE_CONFIG_SYNOPSIS   0x0001
#define NVM_IMAGE_CONFIG_DENALI     0x0002
#define NVM_IMAGE_APPLET_DENALI     0x0003
#define NVM_IMAGE_FIRMWARE          0x0004
#define NVM_IMAGE_OASCLIENT         0x0005
#define NVM_IMAGE_CUSTOM            0x0006
#define NVM_IMAGE_MEMCTL            0x0007
#define NVM_IMAGE_ADVPWRMGMT        0x0008
#define NVM_IMAGE_OAS_CLIENT_IP_STK 0x0009
#define NVM_IMAGE_OAS_CLIENT_TR069  0x000A
#define NVM_IMAGE_NVM_SOFTLOADER    0x000B
#define NVM_IMAGE_FLASH_LAYOUT      0x000C
#define NVM_IMAGE_MANIFEST          0x000E
#define NVM_IMAGE_PIB               0x000F

#define HP_MODULE_END				0xFFFFFFFF
#define PLC_MODULE_SIZE 			1400

/* allowed memory type */
#define HP_MEM_IGNORE                  0x00
#define HP_MEM_AUTO                    0x01
#define HP_MEM_ITCM                    0x02
#define HP_MEM_DTCM                    0x03
#define HP_MEM_SRAM                    0x04
#define HP_MEM_DRAM                    0x05

#define HP_MODULE_MCTL                 0x00
#define HP_MODULE_PIB                  0x01
#define HP_MODULE_FW                   0x02
#define HP_MODULE_NUM					3

#define HP_SEND_MODULE_EXECUTE_BIT     0x01
#define HP_SEND_MODULE_ABSOLUTE_BIT    0x02

#define HP_SEND_MODULE_CLIENT_ID       0x00000000
#define HP_SEND_MODULE_SERVER_ID       0x00000000


#pragma pack(push, 1)
/*added by wanxiangjun*/
typedef struct
{
	UINT8 *mac;
	UINT8 *dak;
}HP_AUTHORIZE_ST;

typedef struct
{
	PLC_DEV_BASE dev;
	char swVer[HP_MAX_SW_VER_LEN];
}HP_SW_VER_ST;

typedef struct 
{
	UINT8 version;
	UINT16 length;
	UINT16 opcode;
	UINT16 block;
	UINT8 *data;
}APFW_UPGRADE_ST;

typedef struct
{
	UINT8 resvd[3];
	UINT8 MII_1LinkStatus;
	UINT8 MII_0LinkStatus;
	UINT8 resvd2[7];
}HP_APFW_GET_DEBUG_ST;

typedef struct 
{
	UINT8 type;
	UINT8 parammeters[10];
}APFW_GET_DEBUG_ST;

typedef struct
{
	UINT8 fileName[HP_UPG_FILE_NAME_MAX_LEN];
	HP_UPG_TYPE_T type;
	UINT32 size;
	UINT8 *data;
}HP_UPG_FILE_INFO_ST;

typedef struct 
{
	UINT8 dak[HP_DAK_LEN];
	UINT8 mac[MAC_ADDR_LEN];
	UINT8 type;
	UINT8 level;
}APCM_AUTHORIZE_REQ_ST;

typedef struct
{
	UINT32 chipVer;
	UINT32 HWVer;
	UINT32 FWVer;
	UINT32 RomVer;
}BCM_STA_INFO_ST;

typedef struct
{
	UINT8 direction;
	UINT8 reserved;
	UINT8 connectInfo;
	UINT8 nvramId;
	UINT8 numOfRules;
	UINT8 ruleId;
	UINT8 reserved2[3];
	UINT8 values[4];
	UINT8 valUnused[12];
}BCM_TOS_BYTE_ST;

typedef struct 
{
	UINT8 subType;
	UINT8 isReadPibOver;
	UINT8 isWritePibOver;
	UINT8 isWriteNvmOver;
	UINT8 modType;
	UINT8 *pib;
	UINT8 *nvm;
	UINT8 *mod;
	UINT32 mSessionID;
	UINT32 modOffset;
	UINT32 modFragmentLen;				/* every packet length of pib or nvm for requesting or writing */
	UINT32 nvmLen;
	UINT32 modLen;
	UINT32 pibLen;
	UINT8 dak[16];
	BOOL  withoutReboot;
}HP_QCA_MOD_OP_ST;/*this ST doesn't need pack*/

typedef struct
{
	UINT8 mac[MAC_ADDR_LEN];
	UINT16 avgTx;
	UINT16 avgRx;
}HP_RMT_STA_ST;

typedef struct
{
	UINT8 numStas;
	HP_RMT_STA_ST stations[HP_MAX_RMT_STA_NUM];	
}APCM_NW_STATS_CNF_ST;

typedef struct
{
	UINT8 modified;
	UINT32 version;
}APSTA_INFO_UCODE_ST;

typedef struct
{
	UINT32 chipVersion;
	UINT32 hwVersion;
	UINT32 fwVersion;
	UINT32 romVersion;
	UINT32 paramConfigBuiltinVersion;
	UINT32 paramConfigNvmVersion;
	UINT8 num_ucodes;
	APSTA_INFO_UCODE_ST *ucodes;
	UINT32 uptime;
	UINT8 fw_boot_msg_len;
	char *fw_boot_msg;
	UINT32 fw_version;
	UINT32 fw_features;
	UINT32 flash_model;
	UINT8 HPAV_version;
	UINT8 maxBitRate;
}APCM_APSTA_INFO_CNF_ST;

typedef struct 
{
	UINT16 paramId;
	UINT8 size;
	UINT16 num;
	UINT8 value[MAX_BCM_PARAM_LEN];
}HP_BCM_PARAM_ST;

typedef struct
{
	UINT32 offset;
	UINT32 size;
	UINT8 value[50];
}HP_BCM_HDR_PARM_ST;

typedef struct 
{
	UINT8 nmk[HP_NMK_LEN];
	UINT8 authType;
	UINT8 SL;
}APCM_SET_KEY_REQ_ST;

typedef struct 
{
	UINT8 bandId;
	UINT8 nid[HP_NID_LEN];
}APCM_NW_STATS_REQ_ST;

typedef struct _HP_PACKET_ID
{
	UINT8 dstMac[MAC_ADDR_LEN];
	UINT8 srcMac[MAC_ADDR_LEN];
	UINT16 etherType;
	UINT8 mmv;
	UINT16 mmType;
}HP_PACKET_ID_ST;

typedef struct _HP_BCM_MME_HEADER
{
	UINT8 dstMac[MAC_ADDR_LEN];
	UINT8 srcMac[MAC_ADDR_LEN];
	UINT16 etherType;
	UINT8 mmv;
	UINT16 mmType;
	UINT8 fmi;
	UINT8 fmsn;
	UINT8 oui[3];
	UINT8 msgId;
}HP_BCM_MME_HEADER_ST;

typedef struct _HP_QCA_MME_HEADER
{
	UINT8 dstMac[MAC_ADDR_LEN];
	UINT8 srcMac[MAC_ADDR_LEN];
	UINT16 etherType;
	UINT8 mmv;
	UINT16 mmType;
	UINT8 oui[3];
}HP_QCA_MME_HEADER_ST;

typedef struct _HP_QCA_MME_HEADER_V1
{
	UINT8 dstMac[MAC_ADDR_LEN];
	UINT8 srcMac[MAC_ADDR_LEN];
	UINT16 etherType;
	UINT8 mmv;
	UINT16 mmType;
	UINT16 FMI;
	UINT8 oui[3];
	UINT8 mmeSubver;
	UINT8 reserved[3];
}HP_QCA_MME_HEADER_V1;

/*end*/
	
typedef struct _HP_SW_VER_CNF
{
	UINT8	status;
	UINT8	deviceID;
	UINT8	length;
	char	verStr[128];
	UINT8	reserved[5];
}HP_SW_VER_CNF;


typedef struct _HP_STATION
{
	UINT8	stationMac[6];
	UINT8	tei;
	UINT8	brigeMac[6];
	UINT8	avgTx;
	UINT8	avgRx;
}HP_STATION;

typedef struct _HP_STATION_V1
{
        UINT8   stationMac[6];
        UINT8   tei;
        UINT8   reserved1[3];
        UINT8   brigeMac[6];
        UINT16  avgTx;
        UINT8   selecCoupling;
        UINT8   reserved2;
        UINT16  avgRx;
        UINT16  reserved3;
}HP_STATION_V1;

typedef struct
{
	UINT8		numAVLNs;
	UINT8		ntwId[7];
	UINT8		sNtwId;
	UINT8		tei;
	UINT8		role;
	UINT8		cooMacAddr[6];
	UINT8		cooTei;
	UINT8		numStations;
	HP_STATION	station[32];
}VS_NW_INFO_CNF;

typedef struct _HP_NW_INFO_CNF_V1
{
        UINT8           reserved1;
        UINT8           numAVLNs;
        UINT8           ntwId[7];
        UINT16          reserved2;
        UINT8           sNtwId;
        UINT8           tei;
        UINT32          reserved3;
        UINT8           role;
        UINT8           cooMacAddr[6];
        UINT8           cooTei;
        UINT8           reserved4[3];
        UINT8           numStations;
        UINT8           reserved5[5];
        HP_STATION_V1   station[32];
} HP_NW_INFO_CNF_V1;

typedef struct
{
	UINT8	eks;
	UINT8	nmk[HP_NMK_LEN];
	UINT8	peks;
	UINT8	staMac[MAC_ADDR_LEN];
	UINT8	staDak[HP_DAK_LEN];
}VS_SET_KEY_REQ_ST;

typedef struct _HP_SET_KEY_CNF
{
	UINT8	status;
}VS_SET_KEY_CNF_ST;

typedef struct
{
	UINT8 	status;
}HP_VS_RS_DEV_CNF;

typedef struct
{
	UINT8 	status;
}HP_FAC_DEF_CNF;


/* VS_RD_MOD REQUEST */
typedef struct _HP_VS_RD_MOD_REQ
{
	UINT8	mModuleID;
	UINT8	mReserved;
	UINT16	mLength;
	UINT32	mOffset;
}HP_VS_RD_MOD_REQ;

/* VS_RD_MOD CONFIRME */
typedef struct _HP_VS_RD_MOD_CNF
{
	UINT8	mStatus;
	UINT8	mReserved[3];
	UINT8	mMoDuleID;
	UINT8	mReserved1;
	UINT16	mLength;
	UINT32	mOffset;
	UINT32	mChkSum;
	UINT8	mData[MAX_HP_VS_MOD_DATA_LEN];
}HP_VS_RD_MOD_CNF;


/* VS_WR_MOD REQUEST */
typedef struct _HP_VS_WR_MOD_REQ			
{
	UINT8	mModuleID;
	UINT8	mReserved;
	UINT16	mLength;						/* Number of bytes to transfer(1-1024) */
	UINT32	mOffset;						/* Offset into module */
	UINT32	mChkSum;
}HP_VS_WR_MOD_REQ;

/* VS_WR_MOD CONFIRME */
typedef struct _HP_VS_WR_MOD_CNF
{
	UINT8	mStatus;
	UINT8	mModuleID;
	UINT8	mReserved;
	UINT16	mLength;						/* Number of bytes transferred(1-1024)*/
	UINT32	mOffset;						/* Offset into module */
}HP_VS_WR_MOD_CNF;


typedef struct _HP_VS_MOD_NVM_REQ
{
	UINT8	mModuleID;
	UINT8	mReserved;
}HP_VS_MOD_NVM_REQ;


typedef struct _HP_VS_MOD_NVM_CNF
{
	UINT8	mStatus;
	UINT8	mMoDuleID;
}HP_VS_MOD_NVM_CNF;


typedef  struct _HP_MOD_OP_REQ_HEADER
{
	UINT32 	mRsvd;			/* Set to 0 */
	UINT8 	mNumOpData;		/* Set to 1 */
	UINT16 	mModOp;			/* Module Operation Id */
}HP_MOD_OP_REQ_HEADER;

typedef  struct _HP_MOD_OP_RD_REQ
{
	UINT16	mModOpDataLen;
	UINT32 	mRsvd;
	UINT16 	mModId;
	UINT16 	mModSubId;
	UINT16 	mDataLen;					/* Number of bytes to transfer (1-1400)*/
	UINT32 	mOffset;				
}HP_MOD_OP_RD_REQ;

typedef  struct _HP_MOD_START_WR_MOD
{
	UINT16 	mModId;
	UINT16 	mModSubId;
	UINT32 	mModLen;					/* Number of bytes transferred (1-1400)*/
	UINT32 	mModChksum;
}HP_MOD_START_WR_MOD;

typedef  struct _HP_MOD_OP_START_WR_SESSION_REQ
{
	UINT16 	mModOpDataLen;
	UINT32 	mRsvd;
	UINT32 	mSessionId;
	UINT8 	mNumMod;
	HP_MOD_START_WR_MOD	mMods[10];		/* most 10 modules support */
}HP_MOD_OP_START_WR_SESSION_REQ;



typedef  struct _HP_MOD_OP_WR_REQ
{
	UINT16 	mModOpDataLen;
	UINT32	mRsvd;
	UINT32 	mSessionId;
	UINT8 	mModIdx;
	UINT16 	mModId;
	UINT16 	mModSubId;
	UINT16 	mDataLen;					
	UINT32 	mOffset;
	UINT8 	mData[1400];		/* 1489 - 24, for pib or nvm */
}HP_MOD_OP_WR_REQ;


typedef  struct _HP_MOD_OP_COMMIT_REQ
{
	UINT16 	mModOpDataLen;
	UINT32 	mRsvd;
	UINT32 	mSessionId;
	UINT32 	mCommitCode;	/* 0x1, 0x2, 0x3, not so sure */
	UINT8 	mRsvds[20];		/* must be set to 0 */
}HP_MOD_OP_COMMIT_REQ;

typedef  struct _HP_MOD_OP_CONF_HEADER
{
	UINT16 	mMStatus;		/* 0x00 = Success */	
	UINT16 	mErrRecCode;
	UINT32 	mRsvd;
	UINT8 	mNumOpData;
	UINT16 	mModOp;
	UINT8 	mData[1482];	/* 1494 - 12 */
}HP_MOD_OP_CONF_HEADER;

typedef  struct _HP_MOD_OP_RD_CONF
{
	UINT16 	mModOpDataLen;
	UINT32 	mRsvd;
	UINT16 	mModId;
	UINT16 	mModSubId;
	UINT16 	mDataLen;
	UINT32 	mOffset;
	UINT8 	mData[1466];	/* 1482 - 16 = 1466 */
}HP_MOD_OP_RD_CONF;

typedef  struct _HP_MOD_STATUS_CONF
{
	UINT16 	mModStatus;
	UINT16 	mErrRecCode;
}HP_MOD_STATUS_CONF;

typedef  struct _HP_MOD_OP_WR_SESSION_CONF
{
	UINT16 	mModOpDataLen;
	UINT32 	mRsvd;
	UINT32 	mSessionId;
	UINT8 	mNumMods;
	HP_MOD_STATUS_CONF 	mMods[10];	/* same as write mod number  */
}HP_MOD_OP_WR_SESSION_CONF;

typedef  struct _HP_MOD_OP_WR_CONF
{
	UINT16 	mModOpDataLen;
	UINT32 	mRsvd;
	UINT32 	mSessionId;
	UINT8 	mModIdx;
	UINT16 	mModId;
	UINT16 	mModSubId;
	UINT16 	mDataLen;
	UINT32 	mOffset;
}HP_MOD_OP_WR_CONF;

typedef  struct _HP_MOD_OP_COMMIT_CONF
{
	UINT16 	mModOpDataLen;
	UINT32 	mRsvd;
	UINT32 	mSessionId;
	UINT32 	mCommitCode;
	UINT8 	mNumMods;
	HP_MOD_STATUS_CONF	mMods[10];	/* same as write mod number */
}HP_MOD_OP_COMMIT_CONF;


typedef struct _HP_PTS_NVM_REQ
{
	UINT8 mModuleID;
	UINT8 mReserved;
	UINT8 mCurrentDAK[16];
}HP_PTS_NVM_REQ;


typedef struct _HP_PTS_NVM_CNF
{
	UINT8 mStatus;
	UINT8 mModuleID;
}HP_PTS_NVM_CNF;



/* for plc recover, add by puhaowen*/
typedef struct _HP_HST_ACT_RSP
{
	UINT8 mStatus;
}HP_HST_ACT_RSP;

typedef struct _HP_WRITE_AND_EXECUTE_APPLET_REQ
{
	UINT32 mClientSessionID;
	UINT32 mServerSessionID;
	UINT32 mFlags;
	UINT8  mAllowedMemTypes[8];
	UINT32 mTotalLength;
	UINT32 mCurrPartLength;
	UINT32 mCurrPartDestAddr;
	UINT32 mStartAddr;
	UINT32 mChecksum;
	UINT8  mReserved[8];
	UINT8  mData[1400];
}HP_WRITE_AND_EXECUTE_APPLET_REQ;

typedef struct _HP_WRITE_AND_EXECUTE_APPLET_CNF
{
	UINT32 mStatus;
	UINT32 mClientSessionID;
	UINT32 mServerSessionID;
	UINT32 mFlags;
	UINT8  mAllowedMemTypes[8];
	UINT32 mTotalLength;
	UINT32 mCurrPartLength;
	UINT32 mCurrPartDestAddr;
	UINT32 mStartAddr;
	UINT32 mChecksum;
	UINT8  mReserved[8];
	UINT32 mCurrPartAbsoluteAddr;
	UINT32 mAbsoluteStartAddr;
}HP_WRITE_AND_EXECUTE_APPLET_CNF;

/***********add by xubo********************/
typedef struct _HP_ENET_SETTINGS_REQ
{
	UINT8 mcontrol;
	UINT8 autonego;
	UINT8 advcp;
	UINT8 espeed;
	UINT8 eduplex;
	UINT8 eflow;
}HP_ENET_SETTINGS_REQ;


typedef struct _HP_ENET_SETTINGS_CNF
{
	UINT8 mStatus;
	UINT8 eSpeed;
	UINT8 eDuplex;
	UINT8 eLinkStatus;/*2-connect, 1-not connect*/
	UINT8 eFlowControl;
}HP_ENET_SETTINGS_CNF;

typedef struct _HP_MDIO_COMMAND_REQ
{
	UINT8 oper;
	UINT8 phyAddr;
	UINT8 regAddr;
	UINT16 data;
}HP_MDIO_COMMAND_REQ;
typedef struct _HP_MDIO_COMMAND_CNF
{
	UINT8 mStatus;
	UINT16 data;
	UINT8 phyAddr;
	UINT8 regAddr;
}HP_MDIO_COMMAND_CNF;


typedef struct _HP_MISTERY_REQ
{
	UINT8 data[38];
}HP_MISTERY_REQ;

typedef struct _HP_MISTERY_CNF
{
	UINT16 mStatus;
	UINT16 mErrRecCode;
}HP_MISTERY_CNF;


/***********************************************************************
*	PIB information
************************************************************************/
typedef struct _HP_PIB_LOCAL_DEV_CFG
{
	UINT8 mac[6];
	UINT8 dak[16];
	UINT8 rsvd1[2];
	UINT8 HFID_manufacture[64];
	UINT8 nmk[16];
	UINT8 HFID_user[64];
	UINT8 HFID_AVLN[64];
	UINT8 cCoSelection;
	UINT8 PreferredNID[7];
	UINT8 rsvd2[11];
	UINT8 mduCfg;
	UINT8 mduRole;
	UINT8 rsvd3[10];
}HP_PIB_LOCAL_DEV_CFG;

/* For Lowcost product, such as AR7420, QCA6410 */
typedef struct _HP_PIB_LOCAL_DEV_CFG_LC
{
	UINT8 mac[6];
	UINT8 dak[16];
	UINT8 rsvd1[2];
	UINT8 HFID_manufacture[64];
	UINT8 nmk[16];
	UINT8 HFID_user[64];
	UINT8 HFID_AVLN[64];
	UINT8 cCoSelection;
}HP_PIB_LOCAL_DEV_CFG_LC;


/*PIB Version */
typedef struct _HP_PIB_VER_HEAD
{
	UINT8 	mFWMajorVersion;
	UINT8	mPIBMinorVersion;
	UINT16	mRSVD;
	UINT16	mPIBLength;
	UINT16	mReserved;
	UINT32	mCheckSum32;
	HP_PIB_LOCAL_DEV_CFG	mLocalDevice;
	UINT8	mNetworCfg[128];
	UINT8	mInterfaceCfg[96];
	UINT8	mIGMPCfg[32];
	UINT8	mUnicastPriority;
	UINT8	mMcastPriority;
	UINT8	mIGMPPriority;
	UINT8	mAVSTreamPriority;
	UINT8	mPriorityTTL[16];
	UINT8	mEnableVLANOver;
	UINT8	mEnableTOSOver;
	UINT8	mRSVD1[2];
	UINT8	mVLANPriorTOSPrecMatrix[4];	
}HP_PIB_VER_HEAD;

typedef struct _EVENT_BLOCK_NEW 
{
	UINT8 EvtPriorityId;
	UINT8 EvtId;
	// Event ID, such as: Power,00;Simple connect,06;ScanningLowPowerMode,11.Power is the same as ScanningLowPowerMode
	UINT8 BehId[3];// the first BehId is behavior ID
	UINT8 ParticipatingGPIOs[2];//the first Participating GPIO is the modify GPIO
	UINT8 mRsvd_mask;
}EVENT_BLOCK_NEW;


typedef struct _PIB_LED_CONFIG_NEW
{
	UINT8 OverrideDefaultLedEventBehavior;
	UINT8 ReportToHostConfig;
	UINT8 NumBehaviors;
	UINT8 NumEvents;
	struct
	{
		UINT8 Behld;
		UINT8 NoOfSteps;
		UINT8 DurationlnMs[12];
		UINT8 GPIOMaskBits[12];
		UINT8 RSVD[2];
	}BehaviorBlockArray[32];
	EVENT_BLOCK_NEW EventBlockArray[48];
	UINT8 PinToGpioNoMapping[6];
	UINT8 InputGpioMask[2];
	UINT8 OutputGpioMask[2];
	UINT8 ControlGpioMask[2];

}PIB_LED_CONFIG_NEW;

typedef struct _HP_PIB_VER_HEAD_LC
{
	UINT8 	mManiHeader[0x3c0];
	UINT8	mRsvd1[12];
	HP_PIB_LOCAL_DEV_CFG_LC mLocalDevice;
	UINT8 	mCoExSel;
	UINT8 	mPLFreqSel;
	UINT8 	mRsvd3;
	UINT8 	mPreferNID[7];
	UINT8 	mRsvd4[11];
	UINT8 	mAuthUpdateLvl;
	UINT8 	mAuthSimpleConnectEnable;
	UINT8 	mNVMAuthKey[16];
	UINT8 	mPIBRdCookie[4];
	UINT8 	mRsvd5[108];
	UINT8 	mCustomerRsvd[64];
	UINT8 	mRsvd6[180];
	UINT8 	mNumPorts;
	UINT8 	mPortInfo[160];
	UINT8 	mOverrideDef;
	UINT8 	mMaxFramesPerSec[4];
	UINT8 	mPortCfgs[96];
	UINT8 	mPhyAddrSel;
	UINT8 	mPhyAddrSelData;
	UINT8 	mRrvd7[0x378];
	UINT8	mUnicastPriority;
	UINT8	mMcastPriority;
	UINT8	mIGMPPriority;
	UINT8	mAVSTreamPriority;
	UINT8	mPriorityTTL[20];
	UINT8	mEnableVLANOver;
	UINT8	mEnableTOSOver;
	UINT8	mRSVD8[2];
	UINT8	mVLANPriorTOSPrecMatrix[4];
	//0x00720
	UINT8   mUnused[4192];
	//0x01780
	PIB_LED_CONFIG_NEW ledConfig;
}HP_PIB_VER_HEAD_LC;

typedef struct _HP_PIB_VER_HEAD_7500
{
	UINT8 	mManiHeader[0x3c0];
	UINT8	mRsvd1[12];
	HP_PIB_LOCAL_DEV_CFG_LC mLocalDevice;
	UINT8 	mCoExSel;
	UINT8 	mPLFreqSel;
	UINT8 	mRsvd3;
	UINT8 	mPreferNID[7];
	UINT8 	mRsvd4[11];
	UINT8 	mAuthUpdateLvl;
	UINT8 	mAuthSimpleConnectEnable;
	UINT8 	mNVMAuthKey[16];
	UINT8 	mPIBRdCookie[4];
	UINT8 	mRsvd5[108];
	UINT8 	mCustomerRsvd[64];
	UINT8 	mRsvd6[180];
	UINT8 	mNumPorts;
	UINT8 	mPortInfo[160];
	UINT8 	mOverrideDef;
	UINT8 	mMaxFramesPerSec[4];
	UINT8 	mPortCfgs[96];
	UINT8 	mPhyAddrSel;
	UINT8 	mPhyAddrSelData;
	UINT8 	mRrvd7[0x378];
	UINT8	mUnicastPriority;
	UINT8	mMcastPriority;
	UINT8	mIGMPPriority;
	UINT8	mAVSTreamPriority;
	UINT8	mPriorityTTL[20];
	UINT8	mEnableVLANOver;
	UINT8	mEnableTOSOver;
	UINT8	mRSVD8[2];
	UINT8	mVLANPriorTOSPrecMatrix[4];
	//0x00720
	UINT8   mUnused[4192];
	UINT8	mUnused_7500[1684];
	//0x01780
	PIB_LED_CONFIG_NEW ledConfig;
}HP_PIB_VER_HEAD_7500;

/* For AR7420 & QCA6410 */
#ifdef STRUCT_FOR_CPP
/*change by xubo*/
	union u
	{
		UINT32 Identifier_AsUint32;
		struct Identifier
		{
			UINT16 Id;
			UINT16 SubId;
		}Identifier;
	};
typedef	struct _HP_NVM_HEADER_LC 
{
	UINT16 MajorVersion;
	UINT16 MinorVersion;
	UINT32 ExecuteMask;
	UINT32 ImageNvmAddress;
	UINT32 ImageAddress;
	UINT32 ImageLength;
	UINT32 ImageChecksum;
	UINT32 EntryPoint;
	UINT32 NextHeader;
	UINT32 PrevHeader;
	UINT32 ImageType;
	union u test;
	UINT16 AppletEntryVersion;
	UINT16 Reserved0;
	UINT32 Reserved1;
	UINT32 Reserved2;
	UINT32 Reserved3;
	UINT32 Reserved4;
	UINT32 Reserved5;
	UINT32 Reserved6;
	UINT32 Reserved7;
	UINT32 Reserved8;
	UINT32 Reserved9;
	UINT32 Reserved10;
	UINT32 Reserved11;
	UINT32 HeaderChecksum;
}HP_NVM_HEADER_LC ;

#endif
#ifndef STRUCT_FOR_CPP

typedef	struct _HP_NVM_HEADER_LC 
{
	UINT16 MajorVersion;
	UINT16 MinorVersion;
	UINT32 ExecuteMask;
	UINT32 ImageNvmAddress;
	UINT32 ImageAddress;
	UINT32 ImageLength;
	UINT32 ImageChecksum;
	UINT32 EntryPoint;
	UINT32 NextHeader;
	UINT32 PrevHeader;
	UINT32 ImageType;
	union 
	{
		UINT32 Identifier_AsUint32;
		struct Identifier
		{
			UINT16 Id;
			UINT16 SubId;
		}Identifier;
	};
	UINT16 AppletEntryVersion;
	UINT16 Reserved0;
	UINT32 Reserved1;
	UINT32 Reserved2;
	UINT32 Reserved3;
	UINT32 Reserved4;
	UINT32 Reserved5;
	UINT32 Reserved6;
	UINT32 Reserved7;
	UINT32 Reserved8;
	UINT32 Reserved9;
	UINT32 Reserved10;
	UINT32 Reserved11;
	UINT32 HeaderChecksum;
}HP_NVM_HEADER_LC ;
#endif
/*************************************************************/
/* QoS Data , see PLC_QOS_CFG*/


typedef struct _HP_NVM_HEADER 
{
	UINT32	mHeaderVersion;
	UINT32	mImageRomaddr;
	UINT32	mImageAddr;
	UINT32	mImageLength;
	UINT32	mImageCheckSum;
	UINT32	mEntryPoint;
	UINT8	mRSVD[12];
	UINT32	mNextHeader;
	UINT32	mHeaderCheckSum;
}HP_STRUCT_HEADER;

/* Common device interface, Added by songwei, 2012/6/20 */
typedef struct _HpAV_Common_Dev_Cfg
{
	UINT8 mac[6];
	UINT8 dak[16];
	UINT8 nmk[16];
}HPAV_COMMON_DEV_CFG;

/* Start pair packet, Added by songwei, 2012/6/28 */
#define HPAV_PAIR_JOIN 1
#define HPAV_PAIR_LEAVE 0
typedef struct _hpav_pair_pkt
{
	UINT8 dstMac[MAC_ADDR_LEN];
	UINT8 srcMac[MAC_ADDR_LEN];
	UINT16 etherType;
	UINT8 mmv;
	UINT16 mmType;
	UINT8 pairAction;
}HPAV_PAIR_PKT;
#pragma pack(pop)

/* for plc recover, add by puhaowen */
typedef struct _HP_QCA_RECOVER_OP_ST
{
	
	UINT8 *nvm;
	UINT32 nvmLen;
	UINT8 *pib;
	UINT32 pibLen;
	BOOL isWriteModOver;
	UINT8 modType;
	UINT8 *modBufAddr;
	UINT32 modMemAddr;
	UINT32 modLength;
	UINT32 modOffset;
	UINT32 modFragmentLen;
	HP_NVM_HEADER_LC modHeader;
	HP_NVM_HEADER_LC *pModHeader[HP_MODULE_NUM];
}HP_QCA_RECOVER_OP_ST;

typedef struct _HP_QCA_MDIO_OP_ST
{
	UINT8 mode;
	UINT8 phy;
	UINT8 reg;
	UINT16 data;
}HP_QCA_MDIO_OP_ST;


#endif 
