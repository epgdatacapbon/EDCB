#pragma once

#include "../../Common/TimeShiftUtil.h"
#include "../../Common/StringUtil.h"
#include "../../Common/PathUtil.h"
#include "../../Common/SendCtrlCmd.h"
#include "../../Common/Util.h"
#include "../../BonCtrl/SendUDP.h"
#include "../../BonCtrl/SendTCP.h"
#include "../../Common/SendCtrlCmd.h"

class CFileStreamingUtil
{
public:
	CFileStreamingUtil(void);
	~CFileStreamingUtil(void);

	BOOL OpenFile(LPCWSTR filePath);
	BOOL OpenTimeShift(LPCWSTR filePath, DWORD processID,DWORD exeCtrlID);
	BOOL StartSend();
	BOOL StopSend();

	//�X�g���[���z�M�Ō��݂̑��M�ʒu�Ƒ��t�@�C���T�C�Y���擾����
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// val				[IN/OUT]�T�C�Y���
	BOOL GetPos(
		NWPLAY_POS_CMD* val
		);

	//�X�g���[���z�M�ő��M�ʒu���V�[�N����
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// val				[IN]�T�C�Y���
	BOOL SetPos(
		NWPLAY_POS_CMD* val
		);

	//�X�g���[���z�M�ő��M���ݒ肷��
	//�߂�l�F
	// �G���[�R�[�h
	//�����F
	// val				[IN]�T�C�Y���
	BOOL SetIP(
		NWPLAY_PLAY_INFO* val
		);

protected:
	CTimeShiftUtil timeShiftUtil;

	CSendUDP sendUdp;
	CSendTCP sendTcp;

	DWORD tcpIP;
	DWORD udpIP;

	vector<HANDLE> udpPortMutex;
	vector<HANDLE> tcpPortMutex;
	vector<NW_SEND_INFO> udpSendList;
	vector<NW_SEND_INFO> tcpSendList;

	HANDLE sizeChkThread;
	HANDLE sizeChkStopEvent;
	CSendCtrlCmd cmd;
	DWORD timeShiftCtrlID;
protected:
	static UINT WINAPI SizeChkThread(LPVOID param);
};

