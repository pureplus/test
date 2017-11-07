/*********************************************************************
 Copyright (C), 2012-2013, TP-LINK TECHNOLOGIES CO., LTD.
 File name:		endian.h
 Description:
				integer byte order declarations and definitions on linux
				
 Author:		Shane(xianjingxiong)
 Create Date:	2013-01-28 14:19
 History:
 ---------------------------------------------------------------------
 ID		Date			Author			Description
 01,	2013-01-28		Shane			create file
 
**********************************************************************/
#ifndef ENDIAN_H
#define ENDIAN_H

#ifdef WIN32
#define BYTE_ORDER	LITTLE_ENDIAN
#else
#include <unistd.h>
#include <endian.h>
#include <byteswap.h>
#endif
#if defined (BYTE_ORDER)
#	if BYTE_ORDER == LITTLE_ENDIAN
#		define BE16TOH(x) __bswap_16(x)
#		define BE32TOH(x) __bswap_32(x)
#		define BE64TOH(x) __bswap_64(x)
#		define HTOBE16(x) __bswap_16(x)
#		define HTOBE32(x) __bswap_32(x)
#		define HTOBE64(x) __bswap_64(x)
#		define LE16TOH(x) (x)
#		define LE32TOH(x) (x)
#		define LE64TOH(x) (x)
#		define HTOLE16(x) (x)
#		define HTOLE32(x) (x)
#		define HTOLE64(x) (x)
#	elif BYTE_ORDER == BIG_ENDIAN
#		define BE16TOH(x) (x)
#		define BE32TOH(x) (x)
#		define BE64TOH(x) (x)
#		define HTOBE16(x) (x)
#		define HTOBE32(x) (x)
#		define HTOBE64(x) (x)
#		define LE16TOH(x) __bswap_16(x)
#		define LE32TOH(x) __bswap_32(x)
#		define LE64TOH(x) __bswap_64(x)
#		define HTOLE16(x) __bswap_16(x)
#		define HTOLE32(x) __bswap_32(x)
#		define HTOLE64(x) __bswap_64(x)
#	else
#		error "Undefined host byte order (2)."
#	endif
#else
#error "Undefined host byte order (1)."
#endif



#endif	/* END OF ENDIAN_H */
