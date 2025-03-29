#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT_XP 0x9C
#define XPT_YP 0xDC
#define XPT_VBAT 0xAC
#define XPT_AUX 0xEC

unsigned int XPT_readAD(unsigned char cmd);

#endif