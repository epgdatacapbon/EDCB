#pragma once

/*
6.2.31 �n�㕪�z�V�X�e���L�q�q�iTerrestrial delivery system descriptor�j
�n�㕪�z�V�X�e���L�q�q�́A�n��`���H�̕����I�����������B�\6�|61 �Q�ƁB

terrestrial_delivery_system_descriptor(){
	descriptor_tag		8 uimsbf
	descriptor_length	8 uimsbf
	area_code			12 bslbf
	guard_interval		2 bslbf
	transmission_mode	2 bslbf
	for(i=0; i<N; i++){
		frequency			16 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
area_code�i�G���A�R�[�h�j�F����12 �r�b�g�̃t�B�[���h�́A�T�[�r�X�G���A�̃R�[�h��
�����B
guard_interval�i�K�[�h�C���^�[�o���j�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|62 �ɏ]
���ăK�[�h�C���^�[�o���������B
transmission_mode�i���[�h���j�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|63 �ɏ]����
���[�h���������B
frequency�i���g���j�F����16 �r�b�g�̃t�B�[���h�́A���S���g���������B���g���P�ʂ�
�n��f�W�^�����������̃`���[�j���O�X�e�b�v�Ɠ���1/7MHz �Ƃ���BMFN �̏ꍇ�́A
�g�p���g���𕡐���L����B

*/

#include "../../../Common/Util.h"

class CTerrestrialDeliverySysDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD area_code;
	BYTE guard_interval;
	BYTE transmission_mode;
	vector<WORD> frequencyList;

public:
	CTerrestrialDeliverySysDesc(void);
	~CTerrestrialDeliverySysDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
