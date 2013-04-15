#pragma once

/*
6.2.49 �T�[�r�X�O���[�v�L�q�q (Service group descriptor)
�T�[�r�X�O���[�v�L�q�q�i�\6-92 �Q�Ɓj�́A�����̃T�[�r�X�ԂɊ֌W������ꍇ�ɁA��
���̃T�[�r�X���O���[�v������Ă��邱�Ƃ��������߂ɗp����B

service_group_descriptor (){
	descriptor_tag 8 uimsbf
	descriptor_length 8 uimsbf
	service_group_type 4 uimsbf
	reserved_future_use 4 uimsbf
	if(service_group_type = = 1){
		for(i=0 ;i< N ; i++){
			primary_service_id 16 uimsbf
			secondary_service_id 16 uimsbf
		}
	}else{
		for(i=0; i< N; i++){
			private_data_byte 8 uimsbf
		}
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
service_group_type�i�T�[�r�X�O���[�v��ʁj�F�����4 �r�b�g�̃t�B�[���h�ŁA�\6�|
93 �ɏ]���A�O���[�v���\������T�[�r�X�̎�ނ�\���B
primary_service_id�i�v���C�}���T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�֘A
�t������̃T�[�r�X�̃T�[�r�X���ʂ������B
secondary_service_id�i�Z�J���_���T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA��
�A�t������̃T�[�r�X�̃T�[�r�X���ʂ������B

*/

#include "../../../Common/Util.h"

class CServiceGroupDesc
{
public:
	typedef struct _SERVICE_GROUP_DATA{
		WORD primary_service_id;
		WORD secondary_service_id;
	} SERVICE_GROUP_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE service_group_type;
	vector<SERVICE_GROUP_DATA> serviceGroupList;

public:
	CServiceGroupDesc(void);
	~CServiceGroupDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
