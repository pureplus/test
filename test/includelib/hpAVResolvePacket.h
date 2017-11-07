
#ifndef _HP_AV_RESOLVE_PACKET_H_
#define _HP_AV_RESOLVE_PACKET_H_

#include "hpAVLib.h"

BOOL hpResolveQCAPkt(HP_TX_PACKET_ST *txBuf, void *paraOut);
BOOL hpResolveBCMPkt(HP_TX_PACKET_ST *txBuf, void *paraOut);

#endif
