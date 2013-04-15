#pragma once

/*
6.2.42 TS ���L�q�q�iTS information descriptor�j
TS ���L�q�q�́A���YTS �Ɋ��蓖�Ă��郊���R���{�^�����ʂ̎w��ƁA�K�w�`����
�ɁA�T�[�r�X���ʂƓ`���K�w�̑Ή��֌W�������B�\6-82 �Q�ƁB

ts_information_descriptor(){
	descriptor_tag 8 uimsbf
	descriptor_length 8 uimsbf
	remote_control_key_id 8 uimsbf
	length_of_ts_name 6 uimsbf
	transmission_type_count 2 uimsbf
	for (i = 0;i< length_of_ts_name;i++) {
		ts_name_char 8 uimsbf
	}
	for (j = 0;j< transmission_type_count;j++) {
		transmission_type_info 8 bslbf
		num_of_service 8 uimsbf
		for (k = 0;k< num_of_service;k++) {
			service_id 16 uimsbf
		}
	}
	for (l = 0;l< N;l++) {
		reserved_future_use 8 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
remote_control_key_id(�����R���L�[����)�F���̂W�r�b�g�̃t�B�[���h�́A���Y�s�r����
�̃����R���{�^���ԍ��Ɋ��蓖�Ă邩�����l�������B
length_of_ts_name�iTS ���L�q���j�F����͂U�r�b�g�̃t�B�[���h�ŁATS ���L�q�̃o�C
�g���������B
transmission_type_count�i�`����ʐ��j�F����͂Q�r�b�g�̃t�B�[���h�ŁA�㑱�̓`����
�ʏ��Ɋւ��郋�[�v���������B
ts_name_char�iTS ���L�q�j�F����͂W�r�b�g�̃t�B�[���h�ł���B��A��TS ���L�q��
�t�B�[���h�́A���Y�s�r�̖��̂��L�q�����B�������̕������Ɋւ��ẮA�t�^�`���Q
�ƁB
transmission_type_info(�`����ʏ��)�F����͂W�r�b�g�̃t�B�[���h�ł���A�`���K�w��
��ʂȂǂɗp�����邪�A���e�͎��Ǝ҂̉^�p�K��ɂ���Ē�߂���B
num_of_service(�T�[�r�X��)�F����͂W�r�b�g�̃t�B�[���h�Ō㑱�̃T�[�r�X���ʂ̃��[
�v���������B
service_id�i�T�[�r�X���ʁj�F����͂P�U�r�b�g�̃t�B�[���h�ŁA�ǂ̓`����ʂ̊K�w�ŁA
�ǂ̃T�[�r�X���ʂ��`������Ă��邩�������B

*/

#include "../../../Common/Util.h"

class CTSInfoDesc
{
public:
	typedef struct _TRANSMISSION_DATA{
		BYTE transmission_type_info;
		BYTE num_of_service;
		vector<WORD> service_idList;
	} TRANSMISSION_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE remote_control_key_id;
	BYTE length_of_ts_name;
	BYTE transmission_type_count;
	CHAR* ts_name_char;
	vector<TRANSMISSION_DATA> transmissionList;
public:
	CTSInfoDesc(void);
	~CTSInfoDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
