#pragma once

#include "FileStreamingUtil.h"
#include "../../Common/Util.h"

class CFileStreamingManager
{
public:
	CFileStreamingManager(void);
	~CFileStreamingManager(void);

	BOOL CloseAllFile(
		);
	BOOL IsStreaming();

	BOOL OpenTimeShift(
		LPCWSTR filePath,
		DWORD processID,
		DWORD exeCtrlID,
		DWORD* ctrlID
		);
	BOOL OpenFile(
		LPCWSTR filePath,
		DWORD* ctrlID
		);
	BOOL CloseFile(
		DWORD ctrlID
		);
	BOOL StartSend(
		DWORD ctrlID
		);
	BOOL StopSend(
		DWORD ctrlID
		);

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
	HANDLE lockEvent;

	DWORD nextCtrlID;
	map<DWORD, CFileStreamingUtil*> utilMap;

protected:
	//PublicAPI�r������p
	BOOL Lock(LPCWSTR log = NULL, DWORD timeOut = 20*1000);
	void UnLock(LPCWSTR log = NULL);

	//���Ɏg�p���鐧��ID���擾����
	//�߂�l�F
	// id
	DWORD GetNextID();
};

