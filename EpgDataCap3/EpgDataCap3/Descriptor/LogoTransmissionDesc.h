#pragma once

/*
6.2.44 ���S�`���L�q�q�iLogo transmission descriptor�j
���S�`���L�q�q�́A�ȈՃ��S�p������ACDT �`���̃��S�ւ̃|�C���e�B���O�Ȃǂ��L�q���邽
�߂Ɏg�p����B�\6-85 �Q�ƁB

logo_transmission_descriptor(){
	descriptor_tag				8 uimsbf
	descriptor_length			8 uimsbf
	logo_transmission_type		8 uimsbf
	if(logo_transmission_type == 0x01){
		reserved_future_use			7 bslbf
		logo_id						9 uimsbf
		reserved_future_use			4 bslbf
		logo_version				12 uimsbf
		download_data_id			16 uimsbf
	}else if(logo_transmission_type == 0x02){
		reserved_future_use			7 bslbf
		logo_id						9 uimsbf
	}else if(logo_transmission_type == 0x03){
		for(i=0;i<N;i++){
			logo_char				8 uimsbf
		}
	}else
		for(j=0;j<M;j++){
			reserved_future_use		8 bslbf
		}
	�p
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
logo_transmission_type�i���S�`����ʁj�F����8 �r�b�g�̃t�B�[���h�́A�\6-86 �Ɏ���
���S�̓`��������\���iARIB STD-B21 �Q�Ɓj�B
logo_id�i���S���ʁj�F����9 �r�b�g�͓��Y�T�[�r�X�ɒ�`���郍�S�f�[�^�̂h�c�l���L��
����iARIB STD-B21 �Q�Ɓj�B
download_data_id�i�_�E�����[�h�f�[�^���ʁj�F����16 �r�b�g�̓_�E�����[�h�����f
�[�^�̎��ʂ�\���B���S�f�[�^���z�u����Ă���CDT ��table_id_extension �̒l�ƈ�v
����iARIB STD-B21 �Q�Ɓj�B
logo_version�i���S�o�[�W�����ԍ��j�F����12 �r�b�g�͓��Ylogo_id �̃o�[�W�����ԍ���
�L�ڂ���iARIB STD-B21 �Q�Ɓj�B
logo_char�i�ȈՃ��S�p������j�F����8 �r�b�g�͊ȈՃ��S�p��8 �P�ʕ�����������L�ڂ�
��B

*/

#include "../../../Common/Util.h"

class CLogoTransmissionDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE logo_transmission_type;
	WORD logo_id;
	WORD logo_version;
	WORD download_data_id;
	BYTE logo_charLength;
	CHAR* logo_char;
public:
	CLogoTransmissionDesc(void);
	~CLogoTransmissionDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
