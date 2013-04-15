#pragma once

#include "EpgDBManager.h"
#include "ReserveManager.h"
#include "SleepUtil.h"
#include "FileStreamingManager.h"
#include "NotifyManager.h"

#include "../../Common/ParseEpgAutoAddText.h"
#include "../../Common/ParseManualAutoAddText.h"
#include "../../Common/PipeServer.h"
#include "../../Common/TCPServer.h"
#include "../../Common/HttpServer.h"
#include "../../Common/TCPServerUtil.h"

#include "DLNAManager.h"

class CEpgTimerSrvMain
{
public:
	CEpgTimerSrvMain(void);
	~CEpgTimerSrvMain(void);

	//���C�����[�v����
	//�����F
	// serviceFlag			[IN]�T�[�r�X�Ƃ��Ă̋N�����ǂ���
	void StartMain(
		BOOL serviceFlag
		);

	//���C��������~
	void StopMain();

	//�x�~�^�X�^���o�C�ڍs���������ǂ���
	//�߂�l�F
	// TRUE�i�ڍs���j�AFALSE
	BOOL IsSuspending();

	//�x�~�^�X�^���o�C�Ɉڍs���č\��Ȃ��󋵂��ǂ���
	//�߂�l�F
	// TRUE�i�\��Ȃ��j�AFALSE�i�ڍs���Ă͑ʖځj
	BOOL ChkSuspend();

	//���[�U�[��PC���g�p�����ǂ���
	//�߂�l�F
	// TRUE�i�g�p���j�AFALSE�i�g�p���Ă��Ȃ��j
	BOOL IsUserWorking();

protected:
	HANDLE lockEvent;

	CEpgDBManager epgDB;
	CReserveManager reserveManager;
	CSleepUtil sleepUtil;
	CFileStreamingManager streamingManager;
	CNotifyManager notifyManager;

	CParseEpgAutoAddText epgAutoAdd;
	CParseManualAutoAddText manualAutoAdd;

	CPipeServer* pipeServer;
	CTCPServer* tcpServer;
	CHttpServer* httpServer;
	CTCPServerUtil* tcpSrvUtil;

	CDLNAManager* dlnaManager;

	HANDLE stopEvent;

	BOOL reloadEpgChkFlag;

	//map<DWORD,DWORD> registGUI; //PID,PID
	//map<wstring,REGIST_TCP_INFO> registTCP; //IP:Port

	BYTE suspendMode;
	BYTE rebootFlag;
	HANDLE sleepThread;
	BYTE suspendModeWork;
	BYTE rebootFlagWork;

	BOOL suspending;

	int wakeMargin;
	BOOL enableTCPSrv;
	DWORD tcpPort;
	int autoAddDays;
	int autoAddHour;
	BOOL chkGroupEvent;
	BYTE rebootDef;
	BOOL ngUsePC;
	DWORD ngUsePCTime;
	BOOL ngFileStreaming;
	BOOL ngEpgFileSrvCoop;
	BOOL enableHttpSrv;
	DWORD httpPort;
	BOOL enableDMS;

	BOOL enableHttpPublic;
	wstring httpPublicFolder;

	BOOL awayMode;

	vector<OLD_EVENT_INFO_DATA3> oldSearchList;
protected:
	//�R�}���h�֌W�r������p
	BOOL Lock(LPCWSTR log = NULL, DWORD timeOut = 60*1000);
	void UnLock(LPCWSTR log = NULL);

	BOOL CheckTuijyu();

	BOOL AutoAddReserveEPG();
	BOOL AutoAddReserveEPG(vector<EPG_AUTO_ADD_DATA>* val);
	BOOL AutoAddReserveEPG(EPG_AUTO_ADD_DATA* item);
	BOOL AutoAddReserveProgram();

	void StartSleep(BYTE rebootFlag, BYTE suspendMode);
	void StartReboot();
	static UINT WINAPI SleepThread(void* param);
	BOOL QuerySleep(BYTE rebootFlag, BYTE suspendMode);
	BOOL QueryReboot(BYTE rebootFlag);

	void ReloadSetting();

	void AddRecFileDMS();

	//�O������R�}���h�֌W
	static int CALLBACK CtrlCmdCallback(void* param, CMD_STREAM* cmdParam, CMD_STREAM* resParam);
	static int CALLBACK HttpCallback(void* param, HTTP_STREAM* recvParam, HTTP_STREAM* sendParam);
	static int CALLBACK TcpAcceptCallback(void* param, SOCKET clientSock, struct sockaddr_in* client, HANDLE stopEvent);


};

