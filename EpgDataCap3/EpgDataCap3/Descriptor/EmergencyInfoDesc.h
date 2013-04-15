#pragma once

/*
6.2.24 �ً}���L�q�q�iEmergency information descriptor�j
�m���n�{���ڂ́A�����ȍ�����21��88��(8)�ɋK�肳��Ă���B
�ً}���L�q�q�i�\6�|40 �Q�Ɓj�́A�����ݔ��K����9 ����3 ��5 ���ɋK�肳���ً}
�x��M���ɏ������M���ł���A�ً}�x��������s���ꍇ�ɗp������B

emergency_information_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for (i=0;i<N;i++){
		service_id				16 uimsbf
		start_end_flag			1 bslbf
		signal_level			1 bslbf
		reserved_future_use		6 bslbf
		area_code_length		8 uimsbf
		for (j=0;j<N;j++){
			area_code				12 bslbf
			reserved_future_use		4 bslbf
		}
	}
}

broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
service_id�i�T�[�r�X���ʁj�F����16 �r�b�g�̃t�B�[���h�͕����ԑg�ԍ��������B�����
program_number �ɓ������B
start_end_flag�i�J�n�^�I���t���O�j�F����1 �r�b�g�̃t���O�́A�X���ȍ�����60 ��405
���Œ�߂���ً}�x��M���̂����A�J�n�M������яI���M���ɑΉ�����B���̃r�b�g��1
�̏ꍇ�A�ً}�x��M�����J�n�������͕������ł��邱�Ƃ������B���̃r�b�g��0 �̏ꍇ�A
�ً}�x��M�����I���������Ƃ������B
signal_level�i�M����ʁj�F����1 �r�b�g�̃t�B�[���h�́A�����ǉ^�p�K����138 ����2
�ɋK�肳���ً}�x��M���̎�ʂɑΉ�����B���̃r�b�g��0 �̏ꍇ�A���������ً}�x
��M������P��J�n�M���ł��邱�Ƃ������B���̃r�b�g��1 �̏ꍇ�A���������ً}�x��
�M������Q��J�n�M���ł��邱�Ƃ������B�i�t�^D �Q�Ɓj
area_code_length�i�n�敄�����j�F�����8 �r�b�g�̃t�B�[���h�ŁA�㑱�̒n�敄���̃o
�C�g���������B
area_code�i�n�敄���j�F�����12 �r�b�g�̃t�B�[���h�ŁA�����ǉ^�p�K����138 ����3
�Œ�߂���n�敄���ɑΉ�����B�n�敄���̊��蓖�ẮA�X���ȍ�����60 ��405 ����
�K�肳�����̂��g�p����B�i�t�^D �Q�Ɓj
*/

#include "../../../Common/Util.h"

class CEmergencyInfoDesc
{
public:
	typedef struct _EMERGENCY_DATA{
		WORD service_id;
		BYTE start_end_flag;
		BYTE signal_level;
		BYTE area_code_length;
		vector<WORD> area_codeList;
	} EMERGENCY_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<EMERGENCY_DATA*> emergencyList;

public:
	CEmergencyInfoDesc(void);
	~CEmergencyInfoDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
protected:
	void Clear();
};
