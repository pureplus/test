
/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:		hpAVLib.h
 Description:
				
				
 Author:		Shane(xianjingxiong)
 Create Date:	2013-01-30 11:20
 History:
 ---------------------------------------------------------------------
 ID		Date			Author			Description
 01,	2013-01-30		Shane			create file
 
**********************************************************************/

#ifndef HP_AVLIB_H
#define HP_AVLIB_H

#ifdef __cplusplus
extern "C" {
#endif
#include "hpStructDef.h"

#define SET_LOCAL_KEY_FLAG	0x0F
#define SET_REMOTE_KEY_FLAG 	0x00

#define INTERFACE_NAME			"eth0"

#define PLC_UKN_NTW_NAME		"Unknown Network Name"
#define PLC_DEF_NTW_NAME		"HomePlugAV"
#define PLC_DEFAULT_NMK			{0x50, 0xD3, 0xE4, 0x93, \
						 		0x3F, 0x85, 0x5B, 0x70, \
						 		0x40, 0x78, 0x4D, 0xF8, \
						 		0x15, 0xAA, 0x8D, 0xB7}


#define DEFAULT_NVM_FILE_PATH	   "/tmp/defaultNvm.nvm"
#define DEFAULT_PIB_FILE_PATH	   "/tmp/defaultPib.pib"
#define DEFAULT_GGL_FILE_PATH	   "/tmp/defaultGgl.ggl"


#define TP_USER_HFID_LEN 26 /* our USER HFID in pib */ 
#define TP_USER_HFID_STR_LEN	23	/* tpver_xxxxxx_yyyyyy_zzz */
#define TP_USER_HFID_VER_LEN	3	/* the "zzz" part in "tpver_xxxxxx_yyyyyy_zzz" */
#define TP_USER_HFID_PREFIX "tpver_"
#define TP_USER_HFID_PREFIX_LEN 6
#define TP_USER_HFID_MODEL_LEN 6

typedef struct _PLC_DEV_ENTRY
{
	UINT8	macAddr[PLC_MAC_ADDR_LEN];	
	UINT8	devPwd[PLC_PWD_LEN + 1];
	UINT8	devName[PLC_DEV_NAME_LEN + 1];
}PLC_DEV_ENTRY;

typedef struct _PLC_DEV_CFG
{
	UINT8 				ntwName[PLC_MAX_NTW_NAME_LEN + 1];
	PLC_DEV_ENTRY 		devsEntry[PLC_MAX_DEV_NUM];
}PLC_DEV_CFG;

typedef struct _PLC_CFG_DATA
{
	PLC_DEV_CFG * pDevCfg;
	PLC_QOS_CFG * pQosCfg;
}PLC_CFG_DATA;


typedef struct _HP_RMT_DEV
{
	PLC_DEV_BASE dev;
	UINT8 isActive;				/* represents if device is active. 1-YES, 0-NO */
	UINT16 avgTx;
	UINT16 avgRx;
}HP_RMT_DEV;


typedef struct _HP_RMT_DEV_INFO
{
	UINT8		remoteDevNum;
	HP_RMT_DEV	remoteDev[HP_MAX_RMT_STA_NUM];
}HP_RMT_DEV_INFO;

typedef PLC_DEV_INFO HP_DEV_INFO;

typedef enum _HOMEPLUG_WRITE_DATA
{
	HP_WRITE_PIB_DATA		= 0,
	HP_WRITE_NVM_DATA		= 1,
	HP_ERRROR_DATA			= 2,	
}HOMEPLUG_WRITE_DATA;

typedef struct _HP_SET_ALL_NMK_PARA
{
	UINT8 			nmk[HP_NMK_LEN];
	PLC_DEV_CFG	plcDevCfg;
}HP_SET_ALL_NMK_PARA;


typedef struct _HP_RESET_ALL_PARA
{
	PLC_DEV_CFG	plcDevCfg;
}HP_RESET_ALL_PARA;

typedef  PLC_UPGRADE_PARA HP_UPGRADE_PARA;

/* add for plc recover, puhaowen*/
typedef struct _HP_RECOVER_PARA
{
	UINT8 *nvm;
	UINT32 nvmLen;
	UINT8 *pib;
	UINT32 pibLen;
	UINT8 *ggl;
	UINT32 gglLen;
	UINT8 mac[MAC_ADDR_LEN];
	UINT8 nmk[HP_NMK_LEN];
}HP_RECOVER_PARA;

typedef struct _HP_RESTORE_CFG_PARA
{
	UINT8 ntwName[HP_NTW_NAME_MAX_LEN];
	PLC_QOS_CFG qosCfg;
}HP_RESTORE_CFG_PARA;

/*add by wanxiangjun*/
typedef struct
{
	UINT8 adapter;
	UINT8 data[MAX_HP_PACKET_SIZE];
	HP_PACKET_ID_ST pktId;
	INT32 size;
}HP_TX_PACKET_ST;

typedef struct {
	UINT8 mac[MAC_ADDR_LEN];
	
}HP_ADAPTER_INFO;

typedef struct 
{
	UINT8 nmk[HP_NMK_LEN];
	UINT8 setKeyFlag;
	UINT8 staMac[MAC_ADDR_LEN];
	UINT8 staDak[HP_DAK_LEN];
}HP_SET_NMK_PARA_ST;

typedef struct
{
	BOOL (*getDevSwVer) (PLC_DEV_BASE *dev, UINT8 *swVer);
	BOOL (*getUserHfid)(PLC_DEV_BASE *dev, UINT8 *hfid);
	BOOL (*getManufactureHfid)(PLC_DEV_BASE *dev, UINT8 *hfid);
	BOOL (*getDevId)(PLC_DEV_BASE *dev, UINT8 *devId);
	BOOL (*getDak)(PLC_DEV_BASE *dev, UINT8 *dak);
    BOOL (*resetDevFacDef)(PLC_DEV_BASE *dev, BOOL isWaitReboot);
	BOOL (*rebootDev)(PLC_DEV_BASE *dev);
    BOOL (*getDevNmk)(PLC_DEV_BASE *dev, UINT8 *nmk);
	BOOL (*setRmtDevNmkWithoutDak)(PLC_DEV_BASE *dev, UINT8 *nmk, BOOL isWaitReboot);
    BOOL (*getNwInfo)(PLC_DEV_BASE *dev, HP_RMT_DEV_INFO *rmtDevInfo);
	BOOL (*getParam)(PLC_DEV_BASE *dev, UINT8 *param, UINT32 *paramSize);
	BOOL (*setParam)(PLC_DEV_BASE *dev, UINT8 *param, UINT32 paramSize);
	BOOL (*getLocalDevCfg)(PLC_DEV_BASE *dev, HP_DEV_INFO *devInfo);
    BOOL (*setQosData)(PLC_DEV_BASE *dev, PLC_QOS_CFG *qosData, BOOL isWaitReboot);
    BOOL (*getQosData)(PLC_DEV_BASE *dev, PLC_QOS_CFG *qosData);
    BOOL (*restore)(PLC_DEV_BASE *dev, HP_RESTORE_CFG_PARA *restorePara);
    BOOL (*upgrade)(PLC_DEV_BASE *dev, HP_UPGRADE_PARA *upgData);
    BOOL (*setLed)(PLC_DEV_BASE *dev, BOOL isLedOn, BOOL isWaitReboot);
	BOOL (*getLed)(PLC_DEV_BASE *dev, BOOL *isLedOn);
	BOOL (*setMac)(PLC_DEV_BASE *dev, PLC_PARAM *param, PLC_SET_MAC_INFO *info);
    BOOL (*addNew)(PLC_DEV_BASE *dev, PLC_DEV_ENTRY *devEntry);
    BOOL (*pushButtonStart)(PLC_DEV_BASE *dev);
    BOOL (*pairConfirm)(PLC_DEV_BASE *dev, UINT8 timeout);
	BOOL (*pushButtonStop)(PLC_DEV_BASE *dev);
	BOOL (*recover)(PLC_DEV_BASE *dev, HP_RECOVER_PARA *recPara);
	BOOL (*getEthSts)(PLC_DEV_BASE *dev, PLC_ETH_INFO *ethInfo);
	BOOL (*setTransMode)(PLC_DEV_BASE *dev, BOOL isMIMO);
	BOOL (*getTransMode)(PLC_DEV_BASE *dev, BOOL *isMIMO);
	BOOL (*getPowerSave)(PLC_DEV_BASE *dev, BOOL *isPowerSave, UINT32 *timeOut);
	BOOL (*setPowerSave)(PLC_DEV_BASE *dev, BOOL isPowerSave, UINT32 timeOut);
}HP_PLC_OPER_LIST;

#ifdef WIN32
#define	sleep(a)	Sleep(a*1000)
#endif
#ifdef WIN32
BOOL hpNicInit(UINT8 *nicNum);
#else
BOOL hpNicInit(const UINT8 *nicName);
#endif
BOOL hpGetNicMac(UINT8 adapter, UINT8 *mac);
BOOL hpPlcScanDev(UINT8 adapter, PLC_DEV_BASE *dev);
BOOL hpGetDevType(PLC_DEV_BASE *dev, HP_DEV_TYPE_T *devType);
BOOL hpPlcReboot(PLC_DEV_BASE *dev);
BOOL hpPlcGetDevSwVer(PLC_DEV_BASE *dev, UINT8 *swVer);
BOOL hpPlcGetDevUserHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
BOOL hpPlcGetDevManufactureHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
BOOL hpPlcGetDevCfg(PLC_DEV_BASE *dev, HP_DEV_INFO *devInfo);
BOOL hpPlcResetDevFacDef(PLC_DEV_BASE *dev);
BOOL hpPlcGetDevNmk(PLC_DEV_BASE *dev, UINT8 *nmk);
BOOL hpPlcSetDevNmk(PLC_DEV_BASE *dev, UINT8 *nmk);
BOOL hpPlcSetAllMembersNmk(PLC_DEV_BASE *dev, UINT8 *ntwName);
BOOL hpPlcGetRmtNwInfo(PLC_DEV_BASE *dev, HP_RMT_DEV_INFO *rmtDevInfo);
BOOL hpPlcSetQos(PLC_DEV_BASE *dev, PLC_QOS_CFG *qosData);
BOOL hpPlcGetQos(PLC_DEV_BASE *dev, PLC_QOS_CFG *qosData);
BOOL hpPlcRestore(PLC_DEV_BASE *dev, HP_RESTORE_CFG_PARA *restorePara);
BOOL hpPlcUpgrade(PLC_DEV_BASE *dev, HP_UPGRADE_PARA *upgData);
BOOL hpPlcGetLed(PLC_DEV_BASE *dev, BOOL *isLedOn);
BOOL hpPlcAddNew(PLC_DEV_BASE *dev, PLC_DEV_ENTRY *devEntry);
BOOL hpPlcPushButtonStart(PLC_DEV_BASE *dev);
BOOL hpPlcPairConfirm(PLC_DEV_BASE *dev, UINT8 timeout);
BOOL hpPlcGetPairStatus(PLC_DEV_BASE *dev, BOOL *isPairing);
BOOL hpPlcPushButtonStop();
BOOL hpPlcNeedRecover(UINT8 adapter, HP_DEV_TYPE_T *devType);
BOOL hpPlcRecover(PLC_DEV_BASE *dev, HP_RECOVER_PARA *recPara);
BOOL hpPlcGetEthStatus(PLC_DEV_BASE *dev, PLC_ETH_INFO *ethInfo);
BOOL hpPlcGetPassword(UINT8 *mac, UINT8 *hfid, UINT8 *password);
BOOL hpPlcGetDevId(PLC_DEV_BASE *dev, UINT8 *devId);
BOOL hpPlcSetMac(PLC_DEV_BASE *dev, PLC_PARAM *param, PLC_SET_MAC_INFO *info);
BOOL hpPlcGetDak(PLC_DEV_BASE *dev, UINT8 *dak);
BOOL hpPlcGetParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 *paramSize);
BOOL hpPlcSetParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 paramSize);
BOOL hpPlcSetLed(PLC_DEV_BASE *dev, BOOL isLedOn);
BOOL hpPlcSetTransMode(PLC_DEV_BASE *dev, BOOL isMIMO);
BOOL hpPlcGetTransMode(PLC_DEV_BASE *dev, BOOL *isMIMO);
BOOL hpPlcGetPowerSave(PLC_DEV_BASE *dev, BOOL *isPowerSave, UINT32 *timeOut);
BOOL hpPlcSetPowerSave(PLC_DEV_BASE *dev, BOOL isPowerSave, UINT32 timeOut);

#ifdef __cplusplus
}
#endif

#endif

