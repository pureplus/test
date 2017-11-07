#ifndef _PLCDEBUG_H_
#define _PLCDEBUG_H_
#include <stdio.h>

/* define for debug */
#if WIN32
#if 1
#define debug(fmt, ...)  do  { printf("[debug](%s:%d): "fmt"\n", __FUNCTION__, __LINE__,  ##__VA_ARGS__); } while(0)
#else
#define debug(fmt, ...) 
#endif

#else

#define PLCD_DEBUG
#ifdef PLCD_DEBUG
#define debug(fmt, args ...) printf("[debug](%s:%d): "fmt"\n", __FUNCTION__, __LINE__, ## args)
#else
#define debug(fmt, args ...)
#endif

#endif

void printf_buf(unsigned char *buf, unsigned int size);
#endif
