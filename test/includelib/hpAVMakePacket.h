/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:		hpAVMakePacket.h
 Description:
				make mme packet.
				
 Author:		Shane(xianjingxiong)
 Create Date:	2013-01-30 17:00
 History:
 ---------------------------------------------------------------------
 ID		Date			Author			Description
 01,	2013-01-30		Shane			create file
 
**********************************************************************/
#ifndef HP_AV_MAKE_PACKET_H
#define HP_AV_MAKE_PACKET_H
#include "hpAVLib.h"


int hpMakeQCAPacket(HP_TX_PACKET_ST *txBuf, void *para);
int hpMakeBCMPacket(HP_TX_PACKET_ST *txBuf, void *para);


#endif
