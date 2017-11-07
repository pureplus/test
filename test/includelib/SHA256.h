/*====================================================================*
 *
 *   SHA256.h - SHA256 encryption declarations and definitions;
 *
 *.  Motley Tools by Charles Maier <cmaier@cmassoc.net>;
 *:  Published 2001-2006 by Charles Maier Associates Limited;
 *;  Released under the GNU General Public Licence v2 and later;
 *
 *--------------------------------------------------------------------*/

#ifndef SHA256_HEADER
#define SHA256_HEADER

/*====================================================================*
 *   system header files;
 *--------------------------------------------------------------------*/


#include <string.h>
//#include <BaseTsd.h>

/*====================================================================*
 *   constants;
 *--------------------------------------------------------------------*/

#define SHA256_DIGEST_LENGTH 256/8

/*====================================================================*
 *   variables;
 *--------------------------------------------------------------------*/

#define INT16 short
#define INT8 char
#define INT32 int
#define UINT8 unsigned char
#define UINT32 unsigned int
#define UINT16 unsigned short
#define ULONG unsigned long
#define USHORT UINT16

typedef struct sha256 

{
	UINT32 count [2];
	UINT32 state [8];
	UINT8 block [64];
	UINT8 extra [64];
}SHA256;

/*====================================================================*
 *   functions;
 *--------------------------------------------------------------------*/

void SHA256Reset (struct sha256 * sha256);
void SHA256Write (struct sha256 * sha256, const void * memory, size_t extent);
void SHA256Block (struct sha256 * sha256, const void * memory);
void SHA256Fetch (struct sha256 * sha256, UINT8 digest []);
void SHA256Print (const UINT8 digest [], char const * string);
void SHA256Ident (signed fd, UINT8 digest []);
signed SHA256Match (signed fd, const UINT8 digest []);

/*====================================================================*
 *
 *--------------------------------------------------------------------*/

#endif 
