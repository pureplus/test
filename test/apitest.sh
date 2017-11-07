#! /bin/bash
export api_name=("plcScanDev"
	"plcGetDevInfo"
	"plcGetSwVersion"
	"plcGetUserHfid"
	"plcGetManufactureHfid"
	"plcGetDevType"
	"plcGetDevId"
	"plcGetNmk"
	"plcGetQos"
	"plcGetLed"
	"plcGetEthStatus"
	"plcGetDak"
	"plcGetNtwInfo"
	"plcGetParam"
	"plcGetPairStatus"
	"plcGetRecoverStatus"
	"plcGetPassword"
	"plcGetNmkFromNtw"
	"plcGetDakFromPwd"
	"plcGetTransMode"
	"plcGetPowerSave"
	"plcSetNetWorkName"
	"plcSetNetWorkNameAll"
	"plcSetQos"
	"plcSetLed"
	"plcSetMac"
	"plcSetParam"
	"plcReset"
	"plcReboot"
	"plcAddDev"
	"plcDeleteDev"
	"plcStartPair"
	"plcStopPair"
	"plcRecover"
	"plcUpgrage"
	"plcSetTransMode"
	"plcSetPowerSave"
	"all")
get_api()
{
	dialog  --backtitle "TEST CONFIG" \
		--checklist "Choose Test Api" 30 50 20 \
	0 "plcScanDev" 1 \
	1 "plcGetDevInfo" 2 \
	2 "plcGetSwVersion" 3 \
	3 "plcGetUserHfid" 4 \
	4 "plcGetManufactureHfid" 5 \
	5 "plcGetDevType" 6 \
	6 "plcGetDevId" 7 \
	7 "plcGetNmk" 8 \
	8 "plcGetQos" 9 \
	9 "plcGetLed" 10 \
	10 "plcGetEthStatus" 11 \
	11 "plcGetDak" 12 \
	12 "plcGetNtwInfo" 13 \
	13 "plcGetParam" 14 \
	14 "plcGetPairStatus" 15 \
	15 "plcGetRecoverStatus" 16 \
	16 "plcGetPassword" 17 \
	17 "plcGetNmkFromNtw" 18 \
	18 "plcGetDakFromPwd" 19 \
	19 "plcGetTransMode" 20 \
	20 "plcGetPowerSave" 21 \
	2>get_info
	get_flag=`cat get_info`
	echo ${get_flag}
}
set_api()
{
	dialog  --backtitle "TEST CONFIG" \
	--checklist "Choose Test Api" 30 50 20 \
	21 "plcSetNetWorkName" 1 \
	22 "plcSetNetWorkNameAll" 1 \
	23 "plcSetQos" 1 \
	24 "plcSetLedOff" 1 \
	25 "plcSetMac" 1 \
	26 "plcSetParam" 1 \
	27 "plcReset" 1 \
	28 "plcReboot" 1 \
	29 "plcAddDev" 1 \
	30 "plcDeleteDev" 1 \
	31 "plcStartPair" 1 \
	32 "plcStopPair" 1 \
	33 "plcRecover" 1 \
	34 "plcUpgrage" 1 \
	35 "plcSetTransMode" 1 \
	36 "plcSetPowerSaveOff" 1 \
	37 "plcSetPowerSaveOn" 1 \
	38 "plcSetLedOn" 1 \
	2>set_info
	local tmp=`cat set_info`
	set_flag=`cat set_info`

}
all_api()
{
	dialog  --backtitle "TEST CONFIG" \
	--checklist "Choose Test Api" 30 50 20 \
	1 "all" 1 \
	2>all_info
	all_flag=`cat all_info`
}
start_test()
{
	local ret
	if [[ ${all_flag} -eq 1 ]];then
			sudo ../test all
			ret=$?
			return ${ret}
	else
		for i in ${get_flag}
		do
			sudo ../test $i
			ret=$?
			if [[ ${ret} -ne 0 ]];then
				return ${ret}	
			fi
			echo ${ret}
		done

		for i in ${set_flag}
		do
			echo set $i
			if [[ $i -eq 37 ]];then
				power_flag=1
				sudo ../test 36 ${power_flag}
			elif [[ $i -eq 38 ]];then
				led_flag=1
				sudo ../test 24 ${led_flag}
			else
				sudo ../test $i				
			fi
			ret=$?
			echo ${ret}
			if [[ ${ret} -ne 0 ]];then
				return ${ret}
			fi
		done
	fi


}
export get_flag
export set_flag
export all_flag=0
export led_flag=0
export power_flag=0

while [[ 1 ]]
do
	dialog --backtitle "PLC DEVICE CONFIG" \
		--title "Config Device" \
		--help-button \
		--cancel-label "Exit" \
		--extra-button --extra-label "StartTest" \
		--menu "Config Dev: ${dev_seq}" 15 60 8 \
		1 "Test GetApi"\
		2 "Test SetApi"\
		3 "Test All"\
		2>menu_config
		menu_choose=$?
		conf_choose=`cat menu_config`
		
	case ${menu_choose} in
		0) #ok
			case ${conf_choose} in
				1)
					get_api;
				;;
				2)
					set_api;
				;;
				3)
					all_api;
				;;
			esac
		;;
		1) #exit
			break;
		;;
		2) #help
		;;
		3) #finish
			start_test;
			ret=$?
			if [[ ${ret} -ne 0 ]];then
				dialog --backtitle "PLC DEVICE CONFIG" \
				--clear --title "Config Device" --msgbox " Test (${api_name[${ret}]}) Fail" 10 60
			else
				dialog --backtitle "PLC DEVICE CONFIG" \
				--clear --title "Config Device" --msgbox "Pass Test" 10 60
			fi
		;;	
	esac

done
# sudo ./test $2 $3

