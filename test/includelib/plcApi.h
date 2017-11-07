 /******************************************************************************
 Copyright (c) 2009-2017 TP-Link Technologies CO.,LTD.	All rights reserved. 
 
 File name	 : plcApi.h
 Version	 : v1.0
 Description : Apis to handle plc device
  
 Author 	 : Pu Haowen <puhaowen@tp-link.com.cn>
 Create date : 2017/2/08
 
 History	 :
 01, 2017/2/08 Pu Haowen, Created file.
 
 *****************************************************************************/

#ifndef PLCAPI_H
#define PLCAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#define PLC_MAX_NIC_NUM			8
#define PLC_MAX_NTW_NAME_LEN	24
#define PLC_MIN_NTW_NAME_LEN	4
#define PLC_PWD_LEN		    	24
#define PLC_SW_VERSION_LEN  	128
#define PLC_ERROR_MESSAGE_LEN	128
#define PLC_MAC_ADDR_LEN  		6
#define PLC_MAC_STR_LEN 		18
#define PLC_DEV_NAME_LEN		24
#define PLC_DAK_LEN             16
#define PLC_NMK_LEN             16
#define PLC_MAX_DEV_NUM			32
#define PLC_PWD_MAX_LEN         24
#define PLC_HFID_LEN            64
#define PLC_PIB_SIZE			0x8000

typedef signed char 		INT8;
typedef signed short		INT16;
typedef signed int			INT32;
typedef unsigned char 		UINT8;
typedef unsigned short 		UINT16;
typedef unsigned int 		UINT32;
typedef unsigned long long	UINT64;

#ifdef WIN32
typedef int     BOOL;
#undef FALSE
#undef TRUE
#undef NULL
#define FALSE   0
#define TRUE    1
#define NULL    0
#else
typedef enum
{
	FALSE = 0,
	TRUE
}BOOL;
#endif

typedef enum {
    PLC_OK = 0,
    PLC_ERR = -1,
    PLC_ERR_INVALID_PARAM = -2,
    PLC_ERR_INVALID_DEVICE = -3,
    PLC_ERR_GET_SW_VERSION = -4,
    PLC_ERR_GET_HFID = -5,
    PLC_ERR_GET_NMK = -6,
    PLC_ERR_GET_QOS = -7,
    PLC_ERR_GET_LED = -8,
    PLC_ERR_GET_ETH_STATUS = -9,
    PLC_ERR_GET_PWD = -10,
    PLC_ERR_GET_NET_INFO = -11,
    PLC_ERR_GET_PARAM = -12,
    PLC_ERR_GET_DAK = -13,
    PLC_ERR_GET_TRANS_MODE = -14,
    PLC_ERR_GET_POWERSAVE = -15,
    PLC_ERR_SET_NMK = -20,
    PLC_ERR_SET_QOS = -21,
    PLC_ERR_SET_LED = -22,
    PLC_ERR_SET_PARAM = -23,
    PLC_ERR_SET_MAC = -24,
    PLC_ERR_SET_TRANS_MODE = -25,
    PLC_ERR_SET_POWERSAVE = -26,
    PLC_ERR_RESET = -40,
    PLC_ERR_REBOOT = -41,
    PLC_ERR_UPGRADE = -42,
    PLC_ERR_ADD_DEVICE = -43,
    PLC_ERR_PAIR = -44,
    PLC_ERR_RECOVER = -45,
    PLC_ERR_UNKNOWN = -100,
} PLC_STATUS;

typedef enum {
    PLC_DEV_TYPE_QCA = 0,
    PLC_DEV_TYPE_BCM,
    PLC_DEV_TYPE_UNKNOWN,
} PLC_DEV_TYPE;

typedef struct _PLC_DEV_BASE {
	UINT8			adapter;
    PLC_DEV_TYPE    type;
	UINT8			devId;
    UINT8           mac[PLC_MAC_ADDR_LEN];
} PLC_DEV_BASE;

typedef struct _PLC_DEV_INFO {
	UINT8   swVer[PLC_SW_VERSION_LEN];
	UINT8	hfid[PLC_HFID_LEN];
	UINT8	dak[PLC_DAK_LEN];
	UINT8 	nmk[PLC_NMK_LEN];
} PLC_DEV_INFO;

typedef struct _PLC_LOCAL_DEV {
    PLC_DEV_BASE    dev;
    PLC_DEV_INFO	devInfo;
} PLC_LOCAL_DEV;

typedef struct _PLC_RMT_DEV {
    PLC_DEV_BASE    dev;
    UINT16          avgTx;
    UINT16          avgRx;
} PLC_RMT_DEV;

typedef struct _PLC_RMT_DEV_INFO {
    UINT8           rmtDevNum;
    PLC_RMT_DEV     rmtDev[PLC_MAX_DEV_NUM];
} PLC_RMT_DEV_INFO;

typedef struct _PLC_QOS_CFG
{
	UINT8	mUnicastPri;
	UINT8	mMcastPri;
	UINT8	mIGMPPri;
	UINT8	mAVSTreamPri;
	UINT8	mEnableVLAN;
	UINT8	mEnableTOS;
	UINT8	mVLANandTOS[16];
}PLC_QOS_CFG;

typedef struct _PLC_UPGRADE_PARA {
    UINT8   *nvm;
    UINT32  nvmLen;
    UINT8   *pib;
    UINT32  pibLen;
    UINT8   *ggl;
    UINT32  gglLen;
} PLC_UPGRADE_PARA;

typedef struct _PLC_RECOVER_PARA {
    UINT8   *nvm;
    UINT32  nvmLen;
    UINT8   *pib;
    UINT32  pibLen;
    UINT8   *ggl;
    UINT32  gglLen;
    UINT8   mac[PLC_MAC_ADDR_LEN];
    UINT8   nmk[PLC_NMK_LEN];
} PLC_RECOVER_PARA;

typedef struct _PLC_PARAM {
	UINT32 	len;
	UINT8	*data;
} PLC_PARAM;

typedef struct _PLC_SET_MAC_INFO {
	UINT8 mac[PLC_MAC_ADDR_LEN];
	UINT8 ntw[PLC_MAX_NTW_NAME_LEN+1];
} PLC_SET_MAC_INFO;

typedef struct _PLC_ETH_INFO {
	BOOL isLink;
	UINT8 speed;  /* 0:10M, 1:100M, 2:1000M, 3:unknown  */
	UINT8 duplex;  /* 0:half, 1:full, 2:unknown  */
} PLC_ETH_INFO;

PLC_STATUS plcNicInit(UINT8 *nicPara);
PLC_STATUS plcGetNicMac(UINT8 adapter, UINT8 *mac);
PLC_STATUS plcScanDev(UINT8 adapter, PLC_DEV_BASE *dev);
PLC_STATUS plcGetDevInfo(PLC_DEV_BASE *dev, PLC_DEV_INFO *devInfo);
PLC_STATUS plcGetSwVersion(PLC_DEV_BASE *dev, UINT8 *swVer);
PLC_STATUS plcGetUserHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
PLC_STATUS plcGetManufactureHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
PLC_STATUS plcGetDevType(PLC_DEV_BASE *dev, PLC_DEV_TYPE *devType);
PLC_STATUS plcGetDevId(PLC_DEV_BASE *dev, UINT8 *devId);
PLC_STATUS plcGetNmk(PLC_DEV_BASE *dev, UINT8 *nmk);
PLC_STATUS plcGetQos(PLC_DEV_BASE *dev, PLC_QOS_CFG *qos);
PLC_STATUS plcGetLed(PLC_DEV_BASE *dev, BOOL *isLedOn);
PLC_STATUS plcGetEthStatus(PLC_DEV_BASE *dev, PLC_ETH_INFO *ethInfo);
PLC_STATUS plcGetDak(PLC_DEV_BASE *dev, UINT8 *dak);
PLC_STATUS plcGetNtwInfo(PLC_DEV_BASE *dev, PLC_RMT_DEV_INFO *rmtInfo);
PLC_STATUS plcGetParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 *paramSize);
PLC_STATUS plcGetPairStatus(PLC_DEV_BASE *dev, BOOL *isPairing);
PLC_STATUS plcGetRecoverStatus(PLC_DEV_BASE *dev, BOOL *isNeedRecover);
PLC_STATUS plcGetPassword(PLC_DEV_BASE *dev, UINT8 *password);
PLC_STATUS plcGetNmkFromNtw(UINT8 *ntw, UINT8 *nmk);
PLC_STATUS plcGetDakFromPwd(UINT8 *pwd, UINT8 *dak);
PLC_STATUS plcGetTransMode(PLC_DEV_BASE *dev, BOOL *isMIMO);
PLC_STATUS plcGetPowerSave(PLC_DEV_BASE *dev, BOOL *isPowerSave);

PLC_STATUS plcSetNetWorkName(PLC_DEV_BASE *dev, UINT8 *ntw);
PLC_STATUS plcSetNetWorkNameAll(PLC_DEV_BASE *dev, UINT8 *ntw);
PLC_STATUS plcSetQos(PLC_DEV_BASE *dev, PLC_QOS_CFG *qos);
PLC_STATUS plcSetLed(PLC_DEV_BASE *dev, BOOL isLedOn);
PLC_STATUS plcSetMac(PLC_DEV_BASE *dev, PLC_PARAM *param, PLC_SET_MAC_INFO *info);
PLC_STATUS plcSetParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 paramSize);
PLC_STATUS plcReset(PLC_DEV_BASE *dev);
PLC_STATUS plcReboot(PLC_DEV_BASE *dev);
PLC_STATUS plcAddDev(PLC_DEV_BASE *dev, UINT8 *password);
PLC_STATUS plcDeleteDev(PLC_DEV_BASE *dev);
PLC_STATUS plcStartPair(PLC_DEV_BASE *dev);
PLC_STATUS plcStopPair(PLC_DEV_BASE *dev);
PLC_STATUS plcRecover(PLC_DEV_BASE *dev, PLC_RECOVER_PARA *para);
PLC_STATUS plcUpgrage(PLC_DEV_BASE *dev, PLC_UPGRADE_PARA *para);
PLC_STATUS plcSetTransMode(PLC_DEV_BASE *dev, BOOL isMIMO);
PLC_STATUS plcSetPowerSave(PLC_DEV_BASE *dev, BOOL isPowerSave);

BOOL plcGetErrorMsg(PLC_STATUS status, UINT8 *msg);
#ifdef __cplusplus
}
#endif
#endif
