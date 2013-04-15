#pragma once

/*
6.2.41 �A�����M�L�q�q�iConnected transmission descriptor�j
�A�����M�L�q�q�́A�n�㉹���`���H�ɂ����ĘA�����M���̕����I�����������B�\6-79 �Q
�ƁB

connected_transmission_descriptor (){
	descriptor_tag						8 uimsbf
	descriptor_length					8 uimsbf
	connected_transmission_group_id		16 uimsbf
	segment_type						2 bslbf
	modulation_type_A					2 bslbf
	modulation_type_B					2 bslbf
	reserved_future_use					2 bslbf
	for(i= 0;i<N;i++){
		additional_connected_transmission_info		8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
connected_transmission_group_id�i�A�����M�O���[�v���ʁj�F����16 �r�b�g�̃t�B�[��
�h�́A�A�����M�O���[�v�����ʂ��郉�x���̖���������B
segment _type�i�Z�O�����g�`����ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6-80 �ɏ]��
�ăZ�O�����g�`���̎�ʂ������B
modulation_type_A�i�ϒ��������A�j�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6-81 �ɏ]��
��A �K�w�̕ϒ������̎�ʂ������B
modulation_type_B�i�ϒ��������B�j�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6-81 �ɏ]��
��B �K�w�̕ϒ������̎�ʂ������B�Z�O�����g�`����ʂ�1 �Z�O�����g�̏ꍇ�́A�Ӗ���
�����Ȃ��B
additional_connected_transmission_info�i�t�����ʏ��j�F����� 8 �r�b�g�̃t�B�[��
�h�ŁA���Ǝ҂̉^�p�K��Œ�߂�⑫���̊i�[�ɗ��p�����B

*/

#include "../../../Common/Util.h"

class CConnectedTransmissionDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD connected_transmission_group_id;
	BYTE segment_type;
	BYTE modulation_type_A;
	BYTE modulation_type_B;
	BYTE additional_connected_transmission_infoLength;
	BYTE* additional_connected_transmission_info;
public:
	CConnectedTransmissionDesc(void);
	~CConnectedTransmissionDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
