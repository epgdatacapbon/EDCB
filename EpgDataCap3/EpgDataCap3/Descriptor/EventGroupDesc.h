#pragma once

/*
6.2.34 �C�x���g�O���[�v�L�q�q�iEvent group descriptor�j
�C�x���g�O���[�v�L�q�q�́A�����̃C�x���g�ԂɊ֌W������ꍇ�ɁA�����̃C�x���g
�Q���O���[�v������Ă��邱�Ƃ��������߂ɗp����B�\6�|67 �Q�ƁB

event_group_descriptor (){
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	group_type					4 uimsbf
	event_count					4 uimsbf
	for(i=0; i< event_count; i++){
		service_id					16 uimsbf
		event_id					16 uimsbf
	}
	if(group_type == 4 || group_type ==5){
		for(i=0 ;i< N ; i++){
			original_network_id		16 uimsbf
			transport_stream_id		16 uimsbf
			service_id				16 uimsbf
			event_id				16 uimsbf
		}
	}else{
		for(i=0; i< N; i++){
			private_data_byte		8 uimsbf
		}
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
group_type�i�O���[�v��ʁj�F�����4 �r�b�g�̃t�B�[���h�ŁA�\6�|68 �ɏ]���A�C�x��
�g�̃O���[�v��ʂ�\���B
event_count�i�C�x���g���[�v���j�F�����4 �r�b�g�̃t�B�[���h�ŁA�㑱��event_id ��
�[�v����\���B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�֘A�t������T�[�r�X
�̃T�[�r�X���ʂ������B�T�[�r�X���ʂ́A�Ή�����v���O�����}�b�v�Z�N�V�������̕���
�ԑg�ԍ����ʁiprogram_number�j�ɓ������B
event_id�i�C�x���g���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�֘A�t����C�x���g�̃C�x
���g���ʂ������B
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F����͂P�U�r�b�g�̃t�B�[���h�ŁA
�l�b�g���[�N���܂�����C�x���g�����[�A�C�x���g�ړ��̍ۂɁA�֘A����C�x���g���`��
����Ă���l�b�g���[�N�̎��ʒl�������B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F����́A�P�U�r�b�g�̃t�B�[��
�h�Ńl�b�g���[�N���܂�����C�x���g�����[�A�C�x���g�ړ��̍ۂɁA�֘A����C�x���g��
�`������Ă���g�����X�|�[�g�X�g���[���̎��ʒl�������B

*/

#include "../../../Common/Util.h"

class CEventGroupDesc
{
public:
	typedef struct _EVENT_DATA{
		WORD service_id;
		WORD event_id;
	}EVENT_DATA;
	typedef struct _EVENT_DATA2{
		WORD original_network_id;
		WORD transport_stream_id;
		WORD service_id;
		WORD event_id;
	}EVENT_DATA2;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE group_type;
	BYTE event_count;
	vector<EVENT_DATA> eventDataList;
	vector<EVENT_DATA2> eventData2List;
	BYTE private_data_byteLength;
	BYTE* private_data_byte;

public:
	CEventGroupDesc(void);
	~CEventGroupDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
