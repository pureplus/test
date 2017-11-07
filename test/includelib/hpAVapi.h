/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:             hpAVapi.h
 Description:
                                
                                
 Author:                Shane(xianjingxiong)
 Create Date:   2013-02-05 14:07
 History:
 ---------------------------------------------------------------------
 ID             Date                    Author                  Description
 01,    2013-02-05              Shane                   create file
 02, 	2015-10-22		wanxiangjun 		add some declare 
**********************************************************************/
#ifndef HP_AV_API_H
#define HP_AV_API_H
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif
#include "hpStructDef.h"
#include "hpAVMakePacket.h"
#include "hpAVResolvePacket.h"
#include "hpAVLib.h"

BOOL hpFreeLocalDev();

BOOL hpCheckBCMDevIsActive(PLC_DEV_BASE *dev);
BOOL hpCheckQCADevIsActive(PLC_DEV_BASE *dev);
BOOL hpCheckRmtDevsIsActive(HP_RMT_DEV_INFO *rmtDevInfo);

BOOL hpQGetHostActionIndicateReq(UINT8 adapter, UINT8 *hstActReq, UINT8 timeout);
BOOL hpBIsBackupFirmware(PLC_DEV_BASE *dev);

BOOL hpScanQCALocalDev(UINT8 adapter, PLC_DEV_BASE *localDev);
BOOL hpGetQCASwVer(PLC_DEV_BASE *dev, UINT8 *swVer);
BOOL hpGetQCAUserHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
BOOL hpGetQCAManufactureHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
BOOL hpGetQCADevId(PLC_DEV_BASE *dev, UINT8 *devId);
BOOL hpGetQCADak(PLC_DEV_BASE *dev, UINT8 *dak);
BOOL hpResetQCAFacDef(PLC_DEV_BASE *dev, BOOL isWaitReboot);
BOOL hpRebootQCADev(PLC_DEV_BASE *dev);
BOOL hpGetQCANmk(PLC_DEV_BASE *dev, UINT8 *nmk);
BOOL hpSetNmkByPib(PLC_DEV_BASE *dev, UINT8 *nmk, BOOL isWaitReboot);
BOOL hpQSetRmtDevNmk(PLC_DEV_BASE *dev, UINT8 *staMac, UINT8 *nmk, UINT8 *staDak);
BOOL hpGetNwInfoFromQCA(PLC_DEV_BASE *dev, HP_RMT_DEV_INFO *rmtDevInfo);
BOOL hpGetQCAParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 *paramSize);
BOOL hpSetQCAParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 paramSize);
BOOL hpGetQCACfg(PLC_DEV_BASE *dev, HP_DEV_INFO *pDevCfg);
BOOL hpQSetQosData(PLC_DEV_BASE *dev, PLC_QOS_CFG *pQosData, BOOL isWaitReboot);
BOOL hpQGetQosData(PLC_DEV_BASE *dev, PLC_QOS_CFG *pQosData);
BOOL hpQCARestore(PLC_DEV_BASE *dev, HP_RESTORE_CFG_PARA *para);
BOOL hpUpgradeNvmAndPib(PLC_DEV_BASE *dev, HP_UPGRADE_PARA *upgData);
BOOL hpQCASetLed(PLC_DEV_BASE *dev, BOOL isLedOn, BOOL isWaitReboot);
BOOL hpQCAGetLed(PLC_DEV_BASE *dev, BOOL *isLedOn);
BOOL hpSetQCAMac(PLC_DEV_BASE *dev, PLC_PARAM *param, PLC_SET_MAC_INFO *info);
BOOL hpQCAAddNew(PLC_DEV_BASE *dev, PLC_DEV_ENTRY *devEntry);
BOOL hpQCAPushButtonStart(PLC_DEV_BASE *dev);
BOOL hpQCAPairConfirm(PLC_DEV_BASE *dev, UINT8 timeout);
BOOL hpQCAPushButtonStop(PLC_DEV_BASE *dev);
BOOL hpQCAPlcRecover(PLC_DEV_BASE *dev, HP_RECOVER_PARA *recPara);
BOOL hpQCAGetEthSts(PLC_DEV_BASE *dev, PLC_ETH_INFO *ethInfo);
//BOOL hpQCAKickLanSta(PLC_DEV_BASE *dev, UINT8 port);
BOOL hpQCASetTransMode(PLC_DEV_BASE *dev, BOOL isMIMO);
BOOL hpQCAGetTransMode(PLC_DEV_BASE *dev, BOOL *isMIMO);
BOOL hpQCAGetPowerSave(PLC_DEV_BASE *dev, BOOL *isPowerSave, UINT32 *timeOut);
BOOL hpQCASetPowerSave(PLC_DEV_BASE *dev, BOOL isPowerSave, UINT32 timeOut);



BOOL hpScanBCMLocalDev(UINT8 adapter, PLC_DEV_BASE *dev);
BOOL hpGetBCMSwVer(PLC_DEV_BASE *dev, UINT8 *swVer);
BOOL hpGetBCMUserHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
BOOL hpGetBCMManufactureHfid(PLC_DEV_BASE *dev, UINT8 *hfid);
BOOL hpBGetLocalDeviceID(PLC_DEV_BASE *dev, UINT8 *deviceID);
BOOL hpGetBCMDevId(PLC_DEV_BASE *dev, UINT8 *devId);
BOOL hpGetBCMDak(PLC_DEV_BASE *dev, UINT8 *dak);
BOOL hpResetBCMFacDef(PLC_DEV_BASE *dev, BOOL isWaitReboot);
BOOL hpRebootBCMDev(PLC_DEV_BASE *dev);
BOOL hpGetBCMParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 *paramSize);
BOOL hpSetBCMParam(PLC_DEV_BASE *dev, UINT8 *param, UINT32 paramSize);
BOOL hpGetBCMNmk(PLC_DEV_BASE *dev, UINT8 *nmk);
BOOL hpSetBCMNmk(PLC_DEV_BASE *dev, UINT8 *nmk, BOOL isWaitReboot);
BOOL hpGetNwInfoFromBCM(PLC_DEV_BASE *dev, HP_RMT_DEV_INFO *rmtDevInfo);
BOOL hpGetBCMCfg(PLC_DEV_BASE *dev, HP_DEV_INFO *devInfo);
BOOL hpBSetQosData(PLC_DEV_BASE *dev, PLC_QOS_CFG *pQosData, BOOL isWaitReboot);
BOOL hpBGetQosData(PLC_DEV_BASE *dev, PLC_QOS_CFG *pQosData);
BOOL hpBCMRestore(PLC_DEV_BASE *dev, HP_RESTORE_CFG_PARA *para);
BOOL hpUpgradeGgl(PLC_DEV_BASE *dev, HP_UPGRADE_PARA *upgData);
BOOL hpBCMSetLed(PLC_DEV_BASE *dev, BOOL isLedOn, BOOL isWaitReboot); 
BOOL hpBCMGetLed(PLC_DEV_BASE *dev, BOOL *isLedOn);
BOOL hpSetBCMMac(PLC_DEV_BASE *dev, PLC_PARAM *param, PLC_SET_MAC_INFO *info);
BOOL hpBCMAddNew(PLC_DEV_BASE *dev, PLC_DEV_ENTRY *devEntry);
BOOL hpBCMPushButtonStart(PLC_DEV_BASE *dev);
BOOL hpBCMPairConfirm(PLC_DEV_BASE *dev, UINT8 timeout);
BOOL hpBCMPushButtonStop(PLC_DEV_BASE *dev);
BOOL hpBCMPlcRecover(PLC_DEV_BASE *dev, HP_RECOVER_PARA *recPara);
BOOL hpBCMGetEthSts(PLC_DEV_BASE *dev, PLC_ETH_INFO *ethInfo);
BOOL hpBCMSetTransMode(PLC_DEV_BASE *dev, BOOL isMIMO);
BOOL hpBCMGetTransMode(PLC_DEV_BASE *dev, BOOL *isMIMO);
BOOL hpBCMGetPowerSave(PLC_DEV_BASE *dev, BOOL *isPowerSave, UINT32 *timeOut);
BOOL hpBCMSetPowerSave(PLC_DEV_BASE *dev, BOOL isPowerSave, UINT32 timeOut);




BOOL hpSemInit();
BOOL hpSemTake();
BOOL hpSemGive();
BOOL hpSemDel();
#endif
