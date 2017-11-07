#include "test.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <dlfcn.h>
#include "plcApi.h"
#include "hpStructDef.h"
#include "hpAVLib.h"
#include "hpAVCommon.h"
#include "hpAVMakePacket.h"
#include "hpAVResolvePacket.h"
#include "hpEndian.h"
#define DLL_FILE_NAME "libplcapi.so"
#define SIML_PIB_LEN 20000
#define SIML_NVM_LEN 60000

static UINT8 tmpbuffer[SIML_NVM_LEN]; 
static UINT8 pibbuffer[SIML_PIB_LEN]; 
static PLC_DEV_BASE test_base;
static PLC_DEV_INFO devInfo;
static UINT32 ret;
static UINT32 g_bool_value;
/************************get info api***************************/
int plcscan(void)
{
  ret = plcScanDev(NULL, &test_base);
  printf("mac:"MAC_FMT"\n", NIPQUAD_mac(test_base.mac));
  printf("PLC_DEV_TYPE %d\n",test_base.type);
  return ret;
}

int plcgetinfo(void)
{
  ret = plcGetDevInfo(&test_base, &devInfo);
  printf("devinfo ret %d\n", ret);
  return ret;
}

int plcgetver(void)
{
  static UINT8 swVer[128];
  ret = plcGetSwVersion(&test_base, swVer);
  printf("ver is %s ret %d\n", swVer, ret);
  return ret;

}

int plcgetuserhfid(void)
{
  static UINT8 hfid[50];
  ret = plcGetUserHfid(&test_base, hfid);
  printf("hfid is %s ret %d\n", hfid, ret);
  return ret;


}

int plcgetmanhfid(void)
{
  static UINT8 mafhfid[50];
  plcGetManufactureHfid(&test_base, mafhfid);
  printf("mafhfid %s ret %d\n", mafhfid, ret);
  return ret;

}
int plcgettype(void)
{
  static UINT32 devType;
  ret = plcGetDevType(&test_base, &devType);
  printf("devtype %d ret %d\n", devType, ret);
  return ret;

}

int plcgetid(void)
{
  static UINT8 devId;
  ret = plcGetDevId(&test_base, &devId);
  printf("devid %d ret %d\n", devId , ret);
  return ret;
}
int plcgetnmk(void)
{
  static UINT8 nmk[HP_NMK_LEN];
  ret = plcGetNmk(&test_base, nmk);
  printf("nmk %s ret %d\n",nmk, ret);
  return ret;

}
int plcgetqos(void)
{
  static PLC_QOS_CFG qos;
  ret  = plcGetQos(&test_base, &qos);
  printf("qos ret %d\n", ret);
  return ret;

}

int plcgetled(void)
{
  static UINT32 isLedOn;
  ret = plcGetLed(&test_base, &isLedOn);
  printf("isledon %d ret %d\n", isLedOn, ret);   
  return ret; 
}
int plcgeteth(void)
{
  static PLC_ETH_INFO ethInfo;
  plcGetEthStatus(&test_base, &ethInfo);
  printf("islink %d\nspeed %d\nduplex %d\n", ethInfo.isLink, ethInfo.speed, ethInfo.duplex);
  return ret;

}
int plcgetdak(void)
{
  static UINT8 dak[128];
  ret = plcGetDak(&test_base, dak);
  printf("dak%s ret %d\n", dak, ret);
  return ret;

}  
int plcgetntw(void)
{
  static PLC_RMT_DEV_INFO rmtInfo;

  // UINT8 dstMac[] = {0x11, 0x11, 0x11, 0x11, 0x11, 0x03};
  // memcpy(rmtInfo.rmtDev[0].dev.mac, dstMac, 6);
  ret = plcGetNtwInfo(&test_base, &rmtInfo);
  printf("retinfo ret%d\n", ret);
  return ret;

}
int plcgetpara(void)
{
  static char tmpbuf[SIML_PIB_LEN];
  PLC_PARAM *para_test = (PLC_PARAM*)calloc(1, sizeof(PLC_PARAM));
  para_test->len = SIML_PIB_LEN;
  para_test->data = tmpbuf;
  ret = plcGetParam(&test_base, para_test->data, &(para_test->len));
  printf("paramsize %d ret %d\n", para_test->len, ret);
  free(para_test);
  return ret;

} 
int plcgetpair(void)
{
  static UINT32 isPairing;
  ret = plcGetPairStatus(&test_base, &isPairing);
  printf("ispairing%d ret %d\n", isPairing, ret );
  return ret;

}  
int  plcgerrecoversta(void)
{
  static UINT32 isNeedRecover;
  ret = plcGetRecoverStatus(&test_base, &isNeedRecover);
  printf("isNeedRecover %d ret %d\n", isNeedRecover, ret);
  return ret;

} 
int plcgetpasswd(void)
{
  static char passwd[30];
  ret = plcGetPassword(&test_base, passwd);
  printf("passwd is %s ret %d\n", passwd, ret);
  return ret;
  
}
int plcgetnmkfromntw(void)
{
  static UINT8 ntw[HP_NTW_NAME_MAX_LEN] = {0x11, 0x22, 0x33, 0x44, 0x55};
  static UINT8 nmk[HP_NMK_LEN];
  ret = plcGetNmkFromNtw(&ntw, nmk);
  printf("nmk %s ret %d\n",nmk, ret);
  return ret;

}   
int plcgetdakfrompwd(void)
{
  static UINT8 pwd[16] = {0x11, 0x22, 0x33, 0x44, 0x55}; 
  static UINT8 dak[HP_DAK_LEN];
  ret = plcGetDakFromPwd(pwd, dak);
  printf("dak ret%d\n", ret);
  return ret;

}  
int plcgettarns(void)
{
  static UINT32 isMIMO;
  ret = plcGetTransMode(&test_base, &isMIMO);
  printf("isMIMO %d  ret %d\n", isMIMO, ret);
  return ret;
  
}  
int plcgetpower(void)
{
  static UINT32 isPowerSave;
  ret = plcGetPowerSave(&test_base, &isPowerSave);
  printf("isPowerSave %d  ret %d\n" ,isPowerSave, ret);
  return ret;

}  

/*************************set api**********************************/
 int plcsetnetname(void)
 {
  static UINT8 set_ntw[] = "tpver_qwerty_asdfgh_999";
  ret = plcSetNetWorkName(&test_base, &set_ntw);
  printf("setnetname ret %d\n", ret);
  return ret;

 }
  
int plcsetnetnameall(void)
{
  static UINT8 set_ntw[] = "tpver_qwerty_asdfgh_999";
  ret = plcSetNetWorkNameAll(&test_base, set_ntw);
  printf("setnetnameall ret %d\n", ret);
  return ret;
  
}
  

int plcsetqos(void)
{
  static PLC_QOS_CFG set_qos;
  ret = plcSetQos(&test_base, &set_qos);
  printf("set qos ret%d\n", ret);
  return ret;

}

int plcsetmac(void)
{
  static char tmpbuf[SIML_PIB_LEN];
  PLC_SET_MAC_INFO *info = (PLC_SET_MAC_INFO*)calloc(1, sizeof(PLC_SET_MAC_INFO));
  memcpy(info->mac, "111113", 6);
  PLC_PARAM *para_test = (PLC_PARAM*)calloc(1, sizeof(PLC_PARAM));
  para_test->len = SIML_PIB_LEN;
  para_test->data = tmpbuf;
  ret = plcGetParam(&test_base, para_test->data, &(para_test->len));/*get pib info*/
  ret = plcSetMac(&test_base, para_test, info);
  printf("setmac ret %d\n", ret);
  plcscan();
  free(para_test);
  free(info);
  return ret;

}  
int plcsetled(void)
{
  UINT32 isLedOn  = g_bool_value;
  ret = plcSetLed(&test_base, isLedOn);
  printf("setled ret %d\n", ret);
  ret = plcGetLed(&test_base, &isLedOn);
  printf("isledon %d ret %d\n", isLedOn, ret);
  return ret;

}  
  
int plcreset(void)
{
  ret = plcReset(&test_base);
  printf("reset ret %d\n", ret);
  return ret;

}  
  
int plcreboot(void)
{
   ret = plcReboot(&test_base);
   printf("reboot ret %d\n", ret);
  return ret;

}  
int plcadddev(void)
{
  static char passwd[30];
  ret = plcGetPassword(&test_base, passwd);
  printf("passwd is %s ret %d\n", passwd, ret);
  ret =  plcAddDev(&test_base, passwd);
  printf("adddev ret %d\n", ret);
  return ret;
 
}  
int plcdeletedev(void)
{
  ret = plcDeleteDev(&test_base);
  printf("deletedev ret %d\n", ret);
  return ret;

} 
int plcstartpair(void)
{
  ret = plcStartPair(&test_base);
  printf("start pair ret %d\n", ret);
  return ret;

}  
int plcstoppair(void)
{

  ret = plcStopPair(&test_base);
  printf("stop pair ret %d\n", ret);
  return ret;

}  
  
int plcsettrans(void)
{
  UINT32 set_isMIMO = g_bool_value;
  ret = plcSetTransMode(&test_base, set_isMIMO);
  printf("set MIMO ret %d\n", ret);
  return ret;

}
 
int plcsetpower(void)
{
  UINT32 set_isPowerSave = g_bool_value;
  ret = plcSetPowerSave(&test_base, set_isPowerSave);
  printf("isPowerSave ret %d\n", ret);
  return ret;

}
int plcsetparam(void)
{
  UINT8 data[SIML_PIB_LEN];
  UINT32 len = SIML_PIB_LEN;
  plcGetParam(&test_base, data, &len);
  ret = plcSetParam(&test_base, data, len);
  printf("setparam ret %d\n", ret);
  return ret;

}
  
/**************up and recover***********************/
static void send_hst_req(UINT8 *mac)
{
 
  UINT8 QCABroadMac[MAC_ADDR_LEN] = {0x00, 0x0C, 0x29, 0x7B, 0x82, 0x12};
  HP_TX_PACKET_ST txBuf;
  memset(&txBuf,0,sizeof(HP_TX_PACKET_ST));

  memcpy(txBuf.pktId.dstMac, mac, MAC_ADDR_LEN);
  memcpy(txBuf.pktId.srcMac, QCABroadMac, MAC_ADDR_LEN);
  txBuf.pktId.etherType = htons(HP_QCA_MTYPE);
  txBuf.pktId.mmv = HP_QCA_MMV;
  txBuf.pktId.mmType = HTOLE16(HP_VS_HST_ACTION | HP_MMTYPE_RSP);

  hpMakeQCAPacket(&txBuf, NULL);
  hpSendPacket(&txBuf);

}
int plcrevr(void)
{
  PLC_RECOVER_PARA rec_para;
  rec_para.nvmLen = SIML_NVM_LEN;
  rec_para.pibLen = SIML_PIB_LEN;
  rec_para.nvm = tmpbuffer;
  rec_para.pib = pibbuffer;
  memcpy(rec_para.mac,test_base.mac, 6);/*set mac*/
  send_hst_req(test_base.mac);
  ret = plcRecover(&test_base, &rec_para);
  printf("recpara ret %d\n", ret);
  return ret;

}
int plcupgrage(void)
{
  PLC_UPGRADE_PARA uppara;
  uppara.nvmLen = SIML_NVM_LEN;
  uppara.pibLen = SIML_PIB_LEN;
  uppara.nvm = tmpbuffer;
  /************get pib info and update******************/
  PLC_PARAM *para_test = (PLC_PARAM*)calloc(1, sizeof(PLC_PARAM));
  para_test->len = SIML_PIB_LEN;
  para_test->data = pibbuffer;
  ret = plcGetParam(&test_base, para_test->data, &(para_test->len));/*get pib info*/
  uppara.pib = para_test->data;
  ret = plcUpgrage(&test_base, &uppara);
  printf("uppara ret %d\n", ret);
  free(para_test);
  return ret;

}

static void fill_head(int *param, UINT32 pre, UINT32 next, UINT32 type)
{
  
  HP_NVM_HEADER_LC *para = (HP_NVM_HEADER_LC*)param;
  para->MajorVersion = 1;
  para->MinorVersion = 1;
  para->PrevHeader = pre;
  para->NextHeader = next;
  para->ImageNvmAddress = 21000;/*relative location*/
  para->ImageAddress = para;
  para->ImageLength =HTOLE32(20904);/*sub head len 96*/
  para->ImageType =HTOLE32(type);

  UINT32 tmp;
  tmp = HTOLE32( GenerateCheckSum(param + sizeof(HP_NVM_HEADER_LC), para->ImageLength >>2) );
  para->ImageChecksum =tmp;
  tmp = checksum32_QCA(param + sizeof(HP_NVM_HEADER_LC), para->ImageLength, 0);

  para->HeaderChecksum  = 0;
  tmp = GenerateCheckSum(para, sizeof(HP_NVM_HEADER_LC) >>2);
 
  para->HeaderChecksum =HTOLE32(tmp);
  tmp = checksum32_QCA(para, sizeof(HP_NVM_HEADER_LC), 0);
 

}
func_interface func_name[FUNC_NUM]=
{
  plcscan,
  plcgetinfo,
  plcgetver,
  plcgetuserhfid,
  plcgetmanhfid,
  plcgettype,
  plcgetid,
  plcgetnmk,
  plcgetqos,
  plcgetled,
  plcgeteth,
  plcgetdak,
  plcgetntw,
  plcgetpara,
  plcgetpair,
  plcgerrecoversta,
  plcgetpasswd,
  plcgetnmkfromntw,
  plcgetdakfrompwd,
  plcgettarns,
  plcgetpower,
  plcsetnetname,
  plcsetnetnameall,
  plcsetqos,
  plcsetled,
  plcsetmac,
  plcsetparam,
  plcreset,
  plcreboot,
  plcadddev,
  plcdeletedev,
  plcstartpair,
  plcstoppair,
  plcrevr,
  plcupgrage,
  plcsettrans,
  plcsetpower

 
}; 
int find_func_name(char *a)
{
  int i;
  if(strlen(a) < 3)/*is number*/
  {
    i = atoi(a);
    if(i >= 0 && i <= FUNC_NUM )
    {
      goto ret;
    }
  }
 
  for(i = 0; i <= FUNC_NUM; i++ )
  {
    if(strcmp(a, func_name_char_arry[i]) == 0)
    {
      goto ret;
    }
  }
  printf("execute function: (%s)\n", func_name_char_arry[0]);
  return 0;
ret:
  printf("execute function: (%s)\n", func_name_char_arry[i]);
  return i;
}
int main(int argc, char**argv)
{
  int ret;
  fill_head(tmpbuffer, -1, SIML_PIB_LEN, NVM_IMAGE_MEMCTL);/*0x0007*/
  fill_head(tmpbuffer+SIML_PIB_LEN, SIML_PIB_LEN, 40000, NVM_IMAGE_FIRMWARE);/*0004*/
  fill_head(tmpbuffer+40000, 40000, -1, NVM_IMAGE_PIB);/*0x000f*/
  fill_head(pibbuffer, -1, -1, NVM_IMAGE_PIB);

  char *a  = "eth0";
  plcNicInit(a);
  func_interface func_tmp;
  func_tmp = func_name[0];
  (*func_tmp)();
  if(argv[2] != NULL)
  {
    g_bool_value = atoi(argv[2]);/*param for setled/setpowersave/settransmode*/ 
    printf("g_bool_value %d\n", g_bool_value);   
  }
  if(argv[1] == NULL)
  {
    return FALSE;
  }
  int i = find_func_name(argv[1]);
  if(i < FUNC_NUM)
  {
    func_tmp = func_name[i];
    ret = (*func_tmp)();    
    return ret? i : ret;
  }
  else /*run all test*/
  {
    for(i = 0; i < FUNC_NUM; i++)
      {
        func_tmp = func_name[i];
        ret = (*func_tmp)();
        if(ret != 0)
        {
          return i;
        }
      }
  }
  return 0;
}