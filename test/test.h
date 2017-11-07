#ifndef _TEST_H_
#define _TEST_H_
/**************************************************************************************************/
/*                                           DEFINES                                              */
/**************************************************************************************************/
#define FUNC_NUM 37
#define MAC_FMT  "%02x:%02x:%02x:%02x:%02x:%02x" /*mac*/
#define NIPQUAD_mac(addr) \
  ((unsigned char *)&addr)[0], \
  ((unsigned char *)&addr)[1], \
  ((unsigned char *)&addr)[2], \
  ((unsigned char *)&addr)[3], \
  ((unsigned char *)&addr)[4], \
  ((unsigned char *)&addr)[5]

/**************************************************************************************************/
/*                                           TYPES                                                */
/**************************************************************************************************/
typedef int(*func_interface)(void);
/**************************************************************************************************/
/*                                           VARIABLES                                            */
/**************************************************************************************************/

char * func_name_char_arry[] =
{
	"plcScanDev",
	"plcGetDevInfo",
	"plcGetSwVersion",
	"plcGetUserHfid",
	"plcGetManufactureHfid",
	"plcGetDevType",
	"plcGetDevId",
	"plcGetNmk",
	"plcGetQos",
	"plcGetLed",
	"plcGetEthStatus",
	"plcGetDak",
	"plcGetNtwInfo",
	"plcGetParam",
	"plcGetPairStatus",
	"plcGetRecoverStatus",
	"plcGetPassword",
	"plcGetNmkFromNtw",
	"plcGetDakFromPwd",
	"plcGetTransMode",
	"plcGetPowerSave",
	"plcSetNetWorkName",
	"plcSetNetWorkNameAll",
	"plcSetQos",
	"plcSetLed",
	"plcSetMac",
	"plcSetParam",
	"plcReset",
	"plcReboot",
	"plcAddDev",
	"plcDeleteDev",
	"plcStartPair",
	"plcStopPair",
	"plcRecover",
	"plcUpgrage",
	"plcSetTransMode",
	"plcSetPowerSave",
	"all"
}; 

#endif