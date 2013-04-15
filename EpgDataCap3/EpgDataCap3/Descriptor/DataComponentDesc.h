#pragma once

/*
6.2.20 �f�[�^�����������L�q�q�iData component descriptor�j
�m���n�{���ڂ́A�����ȍ����� 21 ��88 ��(8)�ɋK�肳��Ă���B
�f�[�^�����������L�q�q�i�\6�|32 �Q�Ɓj�́A�f�[�^���������������ʂ��邽�߂Ɏg�p
�����B

data_component_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	data_component_id		16 uimsbf
	for (i=0;i<N;i++){
		additional_data_component_info	8 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
data_component_id�i�f�[�^�������������ʁj�F����16 �r�b�g�̃t�B�[���h�́A�f�[�^��
���������������ʂ���̂Ɏg�p�����B���̃t�B�[���h�l�̊����ẮA�W�����@�ւ̋K��
�ɂ��B
additional_data_component_info�i�t�����ʏ��j�F�����8 �r�b�g�̃t�B�[���h�ŁA��
�ʎq�ԍ��̊g���A�܂��͕������������ɋK�肳���⑫���̊i�[�Ɏg�p�����B���̗�
��ɋL�q�������̃f�[�^�\���̓f�[�^�������������ɕʓr�K�肷��B�i�t�^J �Q�Ɓj

*/

#include "../../../Common/Util.h"

class CDataComponentDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD data_component_id;
	BYTE additional_data_component_infoLength;
	BYTE* additional_data_component_info;

public:
	CDataComponentDesc(void);
	~CDataComponentDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
