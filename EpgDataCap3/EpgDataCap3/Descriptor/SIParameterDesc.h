#pragma once

/*
6.2.35 SI �`���p�����[�^�L�q�q�iSI parameter descriptor�j
SI �`���p�����[�^�L�q�q�́ASI �̓`���p�����[�^���������߂ɗp����B�\6�|69 �Q�ƁB

SI_parameter_descriptor(){
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	parameter_version			8 uimsbf
	update_time					16 uimsbf
	for(i=0; i<N; i++){
		table_id					8 uimsbf
		table_description_length	8 uimsbf
		for(j=0; j<N; j++){
			table_description_byte		8 uimsbf
		}
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
parameter_version�i�p�����[�^�o�[�W�����j�F����͂W�r�b�g�̃t�B�[���h�ŁASI �̓`
���p�����[�^�̍X�V�ԍ��������B�`���p�����[�^�ɍX�V�����邽�тɁA1 �����������l��
�L�ڂ���B
update_time�i�X�V���j�F�����16 �r�b�g�̃t�B�[���h�ŁA�L�ڂ��ꂽ�`���p�����[�^��
�L���ƂȂ�N������MJD �̉���16 �r�b�g�ŋL�ڂ���B
table_id�i�e�[�u�����ʁj�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̃e�[�u���L�q�o�C�g��
�t�B�[���h�ɋL�q����e�[�u����ʂ������B
table_description_length�i�e�[�u���L�q���j�F����8 �r�b�g�̃t�B�[���h�́A�㑱�̃e�[
�u���L�q�o�C�g�̃o�C�g����\���B
table_description_byte�i�e�[�u���L�q�o�C�g�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��
�A�̃e�[�u���L�q�̈�́A���Ǝ҂̉^�p�K��Œ�߂���e�[�u����ʂ��Ƃ̓`���p����
�[�^���L�q����B



*/

#include "../../../Common/Util.h"

class CSIParameterDesc
{
public:
	typedef struct _EIT_CYCLE{
		BYTE table_cycle_H;
		BYTE table_cycle_M;
		BYTE table_cycle_L;
		BYTE num_of_M_EIT_event;
		BYTE num_of_L_EIT_event;
	}EIT_CYCLE;
	typedef struct _CYCLE_GROUP{
		BYTE num_of_segment;
		BYTE cycle;
	}CYCLE_GROUP;
	typedef struct _H_EIT_CYCLE{
		BYTE media_type;
		BYTE pattern;
		BYTE schedule_range;
		WORD base_cycle;
		BYTE cycle_group_count;
		vector<CYCLE_GROUP> cycleList;
	}H_EIT_CYCLE;
	typedef struct _TABLE_DESC_DATA{
		BYTE table_id;
		BYTE table_description_length;
		BYTE* table_description_byte;
		_TABLE_DESC_DATA(void){
			table_description_byte = NULL;
		}
		~_TABLE_DESC_DATA(void){
			SAFE_DELETE_ARRAY(table_description_byte);
		}
	} TABLE_DESC_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE parameter_version;
	SYSTEMTIME update_time;
	vector<TABLE_DESC_DATA*> tableDescDataList;
public:
	CSIParameterDesc(void);
	~CSIParameterDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

protected:
	void Clear();
};
