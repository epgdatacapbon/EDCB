#pragma once

/*
6.2.37 �R���|�[�l���g�O���[�v�L�q�q�iComponent group descriptor�j
�R���|�[�l���g�O���[�v�L�q�q�́A�C�x���g���̃R���|�[�l���g�̑g�ݍ��킹���`���A
���ʂ���B�\6�|71 �Q�ƁB

component_group_descriptor (){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	component_group_type	3 uimsbf
	total_bit_rate_flag		1 uimsbf
	num_of_group			4 uimsbf
	for(i=0; i< num_of_group; i++){
		component_group_id		4 uimsbf
		num_of_CA_unit			4 uimsbf
		for(i=0; i< num_of_CA_unit; i++){
			CA_unit_id				4 uimsbf
			num_of_component		4 uimsbf
			for(i=0; i< num_of_ component; i++){
				component_tag			8 uimsbf
			}
		}
		if(total_bit_rate_flag==1){
			total_bit_rate			8 uimsbf
		}
		text_length				8 uimsbf
		for(i=0; i< text_length; i++){
			text_char				8 uimsbf
		}
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
component_group_type�i�R���|�[�l���g�O���[�v��ʁj�F�����3 �r�b�g�̃t�B�[���h�ŁA
�\6�|72 �ɏ]���A�R���|�[�l���g�̃O���[�v��ʂ�\���B
total_bit_rate_flag�i���r�b�g���[�g�t���O�j�F�����1 �r�b�g�̃t���O�ŁA�C�x���g����
�R���|�[�l���g�O���[�v���̑��r�b�g���[�g�̋L�q��Ԃ������B���̃r�b�g���u0�v�̏ꍇ�A
�R���|�[�l���g�O���[�v���̑��r�b�g���[�g�t�B�[���h�����Y�L�q�q���ɑ��݂��Ȃ�����
�������B���̃r�b�g���u1�v�̏ꍇ�A�R���|�[�l���g�O���[�v���̑��r�b�g���[�g�t�B�[��
�h�����Y�L�q�q���ɑ��݂��邱�Ƃ������B
num_of_group�i�O���[�v���j�F�����4 �r�b�g�̃t�B�[���h�ŁA�C�x���g���ł̃R���|�[
�l���g�O���[�v�̐��������B
component_group_id�i�R���|�[�l���g�O���[�v���ʁj�F�����4 �r�b�g�̃t�B�[���h�ŁA
�\6�|73 �ɏ]���A�R���|�[�l���g�O���[�v���ʂ��L�q����B
num_of_CA_unit�i�ۋ��P�ʐ��j�F�����4 �r�b�g�̃t�B�[���h�ŁA�R���|�[�l���g�O��
�[�v���ł̉ۋ��^��ۋ��P�ʂ̐��������B
CA_unit_id�i�ۋ��P�ʎ��ʁj�F�����4 �r�b�g�̃t�B�[���h�ŁA�\6�|74 �ɏ]���A�R���|
�[�l���g��������ۋ��P�ʎ��ʂ��L�q����B
num_of_component�i�R���|�[�l���g���j�F�����4 �r�b�g�̃t�B�[���h�ŁA���Y�R���|
�[�l���g�O���[�v�ɑ����A�����O��CA_unit_id �Ŏ������ۋ��^��ۋ��P�ʂɑ�����
�R���|�[�l���g�̐��������B
component_tag�i�R���|�[�l���g�^�O�j�F�����8 �r�b�g�̃t�B�[���h�ŁA�R���|�[�l��
�g�O���[�v�ɑ�����R���|�[�l���g�^�O�l�������B
total_bit_rate�i�g�[�^���r�b�g���[�g�j�F�����8 �r�b�g�̃t�B�[���h�ŁA�R���|�[�l��
�g�O���[�v���̃R���|�[�l���g�̑��r�b�g���[�g���A�g�����X�|�[�g�X�g���[���p�P�b�g
�̓`�����[�g��1/4Mbps ���ɐ؂�グ�ċL�q����B
text_length�i�R���|�[�l���g�O���[�v�L�q���j�F�����8 �r�b�g�̃t�B�[���h�ŁA�㑱��
�R���|�[�l���g�O���[�v�L�q�̃o�C�g����\�킷�B
text_char�i�R���|�[�l���g�O���[�v�L�q�j�F�����8 �r�b�g�̃t�B�[���h�ł���B��A��
�������t�B�[���h�́A�R���|�[�l���g�O���[�v�Ɋւ���������L�q����B�������̕�
�����Ɋւ��ẮA�t�^A ���Q�ƁB

*/

#include "../../../Common/Util.h"

class CComponentGroupDesc
{
public:
	typedef struct _CA_UNIT_DATA{
		BYTE CA_unit_id;
		BYTE num_of_component;
		vector<BYTE> component_tagList;
	} CA_UNIT_DATA;
	typedef struct _COMPONENT_DATA{
		BYTE component_group_id;
		BYTE num_of_CA_unit;
		vector<CA_UNIT_DATA> CAUnitList;
		BYTE total_bit_rate;
		BYTE text_length;
		CHAR* text_char;
		_COMPONENT_DATA(void){
			text_char = NULL;
		}
		~_COMPONENT_DATA(void){
			SAFE_DELETE_ARRAY(text_char);
		}
	} COMPONENT_DATA;

	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE component_group_type;
	BYTE total_bit_rate_flag;
	BYTE num_of_group;
	vector<COMPONENT_DATA*> componentList;

public:
	CComponentGroupDesc(void);
	~CComponentGroupDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );

protected:
	void Clear();
};
