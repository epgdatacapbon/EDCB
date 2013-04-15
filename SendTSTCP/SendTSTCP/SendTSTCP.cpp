// SendTSTCP.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"

#include "../../Common/Util.h"
#include "../../Common/ErrDef.h"
#include "SendTSTCPMain.h"

vector<CSendTSTCPMain*> g_List;
int g_iCount = 0;


//DLL�̏�����
//�߂�l�F����ID�i-1�ŃG���[�j
int WINAPI InitializeDLL(
	)
{
	g_iCount++;
	int iID = 0;
	iID = (int)g_List.size();
	CSendTSTCPMain* pCtrl = new CSendTSTCPMain;
	if(pCtrl->Initialize() == FALSE){
		SAFE_DELETE(pCtrl);
		return -1;
	}
	g_List.push_back(pCtrl);

	return iID;
}


//DLL�̊J��
//�߂�l�F�G���[�R�[�h
DWORD WINAPI UnInitializeDLL(
	int iID //[IN] InitializeDLL�̖߂�l
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	g_List[iID]->UnInitialize();
	SAFE_DELETE(g_List[iID]);

	g_iCount--;
	if( g_iCount < 0 ){
		g_iCount = 0;
	}
	if( g_iCount == 0 ){
		for( int i=0; i<(int)g_List.size(); i++ ){
			SAFE_DELETE(g_List[i]);
		}
		g_List.clear();
	}
	return NO_ERR;
}


//���M���ǉ�
//�߂�l�F�G���[�R�[�h
DWORD WINAPI AddSendAddrDLL(
	int iID, //[IN] InitializeDLL�̖߂�l
	LPCWSTR lpcwszIP,
	DWORD dwPort
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	DWORD dwRet = NO_ERR;
	dwRet = g_List[iID]->AddSendAddr(lpcwszIP, dwPort);
	return dwRet;
}

//���M��N���A
//�߂�l�F�G���[�R�[�h
DWORD WINAPI ClearSendAddrDLL(
	int iID //[IN] InitializeDLL�̖߂�l
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	DWORD dwRet = NO_ERR;
	dwRet = g_List[iID]->ClearSendAddr();
	return dwRet;
}

//�f�[�^���M���J�n
//�߂�l�F�G���[�R�[�h
DWORD WINAPI StartSendDLL(
	int iID //[IN] InitializeDLL�̖߂�l
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	DWORD dwRet = NO_ERR;
	dwRet = g_List[iID]->StartSend();
	return dwRet;
}

//�f�[�^���M���~
//�߂�l�F�G���[�R�[�h
DWORD WINAPI StopSendDLL(
	int iID //[IN] InitializeDLL�̖߂�l
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	DWORD dwRet = NO_ERR;
	dwRet = g_List[iID]->StopSend();
	return dwRet;
}

//�f�[�^���M���J�n
//�߂�l�F�G���[�R�[�h
DWORD WINAPI AddSendDataDLL(
	int iID, //[IN] InitializeDLL�̖߂�l
	BYTE* pbData,
	DWORD dwSize
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	DWORD dwRet = NO_ERR;
	dwRet = g_List[iID]->AddSendData(pbData, dwSize);
	return dwRet;
}

//���M�o�b�t�@���N���A
//�߂�l�F�G���[�R�[�h
DWORD WINAPI ClearSendBuffDLL(
	int iID //[IN] InitializeDLL�̖߂�l
	)
{
	if( g_List[iID] == NULL ){
		return ERR_NOT_INIT;
	}
	DWORD dwRet = NO_ERR;
	dwRet = g_List[iID]->ClearSendBuff();
	return dwRet;
}
