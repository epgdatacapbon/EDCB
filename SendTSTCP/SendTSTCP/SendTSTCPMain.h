#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>

#include "../../Common/Util.h"
#include "../../Common/StringUtil.h"
#pragma comment(lib, "wsock32.lib")

class CSendTSTCPMain
{
public:
	CSendTSTCPMain(void);
	~CSendTSTCPMain(void);

	//DLL�̏�����
	//�߂�l�FTRUE:�����AFALSE:���s
	BOOL Initialize(
		);

	//DLL�̊J��
	//�߂�l�F�Ȃ�
	void UnInitialize(
		);

	//���M���ǉ�
	//�߂�l�F�G���[�R�[�h
	DWORD AddSendAddr(
		LPCWSTR lpcwszIP,
		DWORD dwPort
		);

	//���M��N���A
	//�߂�l�F�G���[�R�[�h
	DWORD ClearSendAddr(
		);

	//�f�[�^���M���J�n
	//�߂�l�F�G���[�R�[�h
	DWORD StartSend(
		);

	//�f�[�^���M���~
	//�߂�l�F�G���[�R�[�h
	DWORD StopSend(
		);

	//�f�[�^���M���J�n
	//�߂�l�F�G���[�R�[�h
	DWORD AddSendData(
		BYTE* pbData,
		DWORD dwSize
		);

	//���M�o�b�t�@���N���A
	//�߂�l�F�G���[�R�[�h
	DWORD ClearSendBuff(
		);


protected:
	HANDLE m_hStopConnectEvent;
	HANDLE m_hConnectThread;
	HANDLE m_hStopSendEvent;
	HANDLE m_hSendThread;

	HANDLE m_hEvent;
	HANDLE m_hEvent2;

	typedef struct _TS_DATA{
		BYTE* pbBuff;
		DWORD dwSize;
		_TS_DATA(void){
			pbBuff = NULL;
			dwSize = 0;
		}
		~_TS_DATA(void){
			SAFE_DELETE_ARRAY(pbBuff);
		}
	}TS_DATA;
	vector<TS_DATA*> m_TSBuff;

	typedef struct _SEND_INFO{
		wstring strIP;
		DWORD dwIP;
		DWORD dwPort;
		SOCKET sock;
		struct sockaddr_in addr;
		BOOL bConnect;
	}SEND_INFO;
	map<wstring, SEND_INFO> m_SendList;

protected:
	BOOL Lock();
	void UnLock();
	BOOL Lock2();
	void UnLock2();

	static UINT WINAPI SendThread(LPVOID pParam);
	static UINT WINAPI ConnectThread(LPVOID pParam);

};
