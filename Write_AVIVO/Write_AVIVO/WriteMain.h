#pragma once

#include "../../Common/Util.h"
#include "../../Common/StringUtil.h"
#include "../../Common/PathUtil.h"

#include "DShowCtrl.h"

class CWriteMain
{
public:
	CWriteMain(void);
	~CWriteMain(void);
	
	//�t�@�C���ۑ����J�n����
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// fileName				[IN]�ۑ��t�@�C���t���p�X�i�K�v�ɉ����Ċg���q�ς�����ȂǍs���j
	// overWriteFlag		[IN]����t�@�C�������ݎ��ɏ㏑�����邩�ǂ����iTRUE�F����AFALSE�F���Ȃ��j
	// createSize			[IN]���͗\�z�e�ʁi188�o�C�gTS�ł̗e�ʁB�����^�掞�ȂǑ����Ԗ���̏ꍇ��0�B�����Ȃǂ̉\��������̂Ŗڈ����x�j
	BOOL _StartSave(
		LPCWSTR fileName,
		BOOL overWriteFlag,
		ULONGLONG createSize,
		HINSTANCE hInstance
		);

	//�t�@�C���ۑ����I������
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	BOOL _StopSave(
		);

	//���ۂɕۑ����Ă���t�@�C���p�X���擾����i�Đ���o�b�`�����ɗ��p�����j
	//filePath��NULL���͕K�v�ȃT�C�Y��filePathSize�ŕԂ�
	//�ʏ�filePathSize=512�ŌĂяo��
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// filePath				[OUT]�ۑ��t�@�C���t���p�X
	// filePathSize			[IN/OUT]filePath�̃T�C�Y(WCHAR�P��)
	BOOL _GetSaveFilePath(
		WCHAR* filePath,
		DWORD* filePathSize
		);

	//�ۑ��pTS�f�[�^�𑗂�
	//�󂫗e�ʕs���Ȃǂŏ����o�����s�����ꍇ�AwriteSize�̒l������
	//�ēx�ۑ���������Ƃ��̑��M�J�n�n�_�����߂�
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// data					[IN]TS�f�[�^
	// size					[IN]data�̃T�C�Y
	// writeSize			[OUT]�ۑ��ɗ��p�����T�C�Y
	BOOL _AddTSBuff(
		BYTE* data,
		DWORD size,
		DWORD* writeSize
		);

protected:
	wstring savePath;
	CDShowCtrl dshowCtrl;

protected:
	BOOL GetNextFileName(wstring filePath, wstring& newPath);
};

