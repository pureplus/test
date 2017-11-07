/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:		ifopr.h
 Description:
				define nic operation interface.
				supply sending and reading raw packets capabilities.
				
 Author:		Shane(xianjingxiong)
 Create Date:	2013-01-15 17:44
 History:
 ---------------------------------------------------------------------
 ID		Date			Author			Description
 01,	2013-01-15		Shane			create file
 02,	2017-3-5		Pu Haowen		support multi NIC
**********************************************************************/

#ifndef	IFOPR_H
#define IFOPR_H

#include <net/if.h>		/* include IFNAMSIZ */

#define IF_ADDR_LEN	6
#define IFOPR_ERRBUF_SIZE 256
#define IFOPR_NAME_SIZE IFNAMSIZ		/* 16 */

#define _setbits(flag,mask) flag |=  (mask)
#define _clrbits(flag,mask) flag &= ~(mask)


struct IFOPR_IF
{
	char 			ifname[IFOPR_NAME_SIZE];	/* interface name */
	int				ifindex;					/* interface index */
   	unsigned char 	ifaddr[IF_ADDR_LEN];		/* interface hardware addr*/
};

struct IFOPR_IF_LIST
{
	struct IFOPR_IF *		ifinfo;
	struct IFOPR_IF_LIST *	next;
};

struct IFOPR_HANDLE
{
	int 	sockfd[2];
	int     ms_to;		/* poll timeout in ms */
	struct 	IFOPR_IF *	ifinfo;
	char	errbuf[IFOPR_ERRBUF_SIZE];
};



int ifopr_findalldevs(struct IFOPR_IF_LIST **alldevsp, char *errbuf);
void ifopr_freealldevs(struct IFOPR_IF_LIST *alldevsp);
const char* ifopr_lookupdev(char * errbuf);

struct IFOPR_HANDLE *ifopr_open(const char *ifname, int ms_to, char *errbuf);
int ifopr_close(struct IFOPR_HANDLE *handle, char *errbuf);

int ifopr_sendpkt(struct IFOPR_HANDLE *handle, unsigned char devType, void *memory, int size);
int ifopr_readpkt(struct IFOPR_HANDLE *handle, unsigned char devType, void *memory, int size);


#endif	/* END OF IFOPR_H */





