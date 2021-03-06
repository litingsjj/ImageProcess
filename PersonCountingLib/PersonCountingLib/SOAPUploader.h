//大屏幕公司显示驱动程序
#ifndef _SOAP_UPLOADER
#define _SOAP_UPLOADER
#pragma once
#include "stdafx.h"
#include "uploader/UpdateStudentStatusSoap.nsmap"
//#include "uploader/doupload.h"
#include "uploader/soapUpdateStudentStatusSoapProxy.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

extern string upload_username = "junfatech";      //显示系统上传账户
extern string upload_pwd = "junfatech";           //显示系统上传密码

struct upload_data_package
{
	string chlname;
	int studentCount;
	string updateTime;
};

time_t convert_string_to_time_t(const std::string & time_string)
{
	struct tm tm1;
	time_t time1;
	int i = sscanf(time_string.c_str(), "%d-%d-%d %d:%d:%d",
		&(tm1.tm_year),
		&(tm1.tm_mon),
		&(tm1.tm_mday),
		&(tm1.tm_hour),
		&(tm1.tm_min),
		&(tm1.tm_sec),
		&(tm1.tm_wday),
		&(tm1.tm_yday));

	tm1.tm_year -= 1900;
	tm1.tm_mon--;
	tm1.tm_isdst = -1;
	time1 = mktime(&tm1);

	return time1;
}

string transfer_to_ret_str(int val)
{
	val--;
	string retStr[] = { "OK", "Saving failed.", "Classroom not found", "Update failed", "Wrong pwd/username","Dataset storage error" };
	return retStr[val];
}

void do_soap_upload(string chlname, int studentCount, string updateTime)
{
	struct soap *soap;
	soap = soap_new();

	
	struct _ns1__UpdateClassRoomPersonStatus toSend;
	struct _ns1__UpdateClassRoomPersonStatusResponse toRecv;

	//toSend.account = "junfatech";
	//toSend.password = "junfatech";
	toSend.account = (char*)upload_username.data();
	toSend.password = (char*)upload_pwd.data();
	int len = 4;
	chlname = chlname.substr(0, len);
	//toSend.roomNo = (char *)malloc((len + 1)*sizeof(char));
	//chlname.copy(toSend.roomNo, len, 0);
	//toSend.roomNo=(char*)chlname.substr(0,len).data();
	toSend.roomNo = (char*)chlname.data();
	cout << toSend.roomNo << endl;
	toSend.studentCount = studentCount;
	toSend.updateTime = convert_string_to_time_t(updateTime);
	
	//send request.
	UpdateStudentStatusSoapProxy service;
	if (service.UpdateClassRoomPersonStatus(&toSend, toRecv) == SOAP_OK)
		cout << "Return result:" << transfer_to_ret_str(toRecv.UpdateClassRoomPersonStatusResult) << endl;
	else
	{
		service.soap_stream_fault(std::cerr);
		cout << "Connect to server failed..." << endl;
	}
	service.destroy();

}

void SOAPMain()
{
	MSG Msg1;
	while (true)
	{
		if (GetMessage(&Msg1, NULL, 0, 0))
		{
			upload_data_package* now_data;
			now_data = (upload_data_package*)(Msg1.wParam);
			do_soap_upload(now_data->chlname, now_data->studentCount, now_data->updateTime);
			delete(now_data); 
		}
		Sleep(100);
	}
}

#endif