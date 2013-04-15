#pragma once

#include "../../Common/Util.h"
#include "../../Common/EpgTimerUtil.h"
#include "../../Common/PathUtil.h"
#include "../../Common/StringUtil.h"
#include "../../Common/ParseChText4.h"

#include "TunerCtrl.h"
#include "TunerBankCtrl.h"

class CTunerManager
{
public:
	CTunerManager(void);
	~CTunerManager(void);

	//�`���[�i�[�ꗗ�̓ǂݍ��݂��s��
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	BOOL ReloadTuner();

	//�`���[�i�[��ID�ꗗ���擾����B
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// idList			[OUT]�`���[�i�[��ID�ꗗ
	BOOL GetEnumID(
		vector<DWORD>* idList
		);

	//�`���[�i�[�\�񐧌���擾����
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// ctrlMap			[OUT]�`���[�i�[�\�񐧌�̈ꗗ
	BOOL GetEnumTunerBank(
		map<DWORD, CTunerBankCtrl*>* ctrlMap
		);

	//�w��T�[�r�X���T�|�[�g���Ă��Ȃ��`���[�i�[�ꗗ���擾����
	//�߂�l�F
	// TRUE�i�����j�AFALSE�i���s�j
	//�����F
	// ONID				[IN]�m�F�������T�[�r�X��ONID
	// TSID				[IN]�m�F�������T�[�r�X��TSID
	// SID				[IN]�m�F�������T�[�r�X��SID
	// idList			[OUT]�`���[�i�[��ID�ꗗ
	BOOL GetNotSupportServiceTuner(
		WORD ONID,
		WORD TSID,
		WORD SID,
		vector<DWORD>* idList
		);

	BOOL GetSupportServiceTuner(
		WORD ONID,
		WORD TSID,
		WORD SID,
		vector<DWORD>* idList
		);

	BOOL GetCh(
		DWORD tunerID,
		WORD ONID,
		WORD TSID,
		WORD SID,
		DWORD* space,
		DWORD* ch
		);

	BOOL GetEnumEpgCapTuner(
		vector<DWORD>* idList
		);

	BOOL IsSupportService(
		DWORD tunerID,
		WORD ONID,
		WORD TSID,
		WORD SID
		);

	BOOL GetBonFileName(
		DWORD tunerID,
		wstring& bonFileName
		);

protected:
	typedef struct _TUNER_INFO{
		WORD bonID;
		WORD tunerID;
		wstring bonFileName;
		BOOL epgCapFlag;
		CParseChText4 chUtil;
		wstring chSet4FilePath;
	}TUNER_INFO;

	map<DWORD, TUNER_INFO*> tunerMap; //�L�[ bonID<<16 | tunerID
protected:
	BOOL FindBonFileName(wstring src, wstring& dllName);
};

