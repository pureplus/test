/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:		hpifopr.h
 Description:
				define interface operation interface.
				supply sending and reading homeplug av packets capabilities.
				
 Author:		Shane(xianjingxiong)
 Create Date:	2013-01-31 17:00
 History:
 ---------------------------------------------------------------------
 ID		Date			Author			Description
 01,	2013-01-31		Shane			create file
 
**********************************************************************/
#ifndef HP_IF_OPR_H
#define HP_IF_OPR_H

#ifdef __cplusplus
extern "C" {
#endif
#include "hpStructDef.h"
#include "hpAVLib.h"
#ifdef WIN32
#include "pcap.h"
#include "WinPcapApi.h"
#else 
#include "ifopr.h"
#include <sys/time.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

#include "hpEndian.h"
#include "plcDebug.h"
#endif

#ifdef WIN32
BOOL openif(UINT8 *ifNum);
BOOL openNICs();
BOOL closeNICs();
#else
BOOL openif(const char *ifname);
BOOL closeif();
#endif
BOOL hpGetIfMac(UINT8 adapter, UINT8 *mac);
BOOL hpSendPacket(HP_TX_PACKET_ST *txBuf);
BOOL hpWaitForRcvPkt(HP_TX_PACKET_ST *txBuf, int to);
BOOL hpReadPacket(HP_TX_PACKET_ST *txBuf);

#ifdef __cplusplus
}
#endif
#endif
