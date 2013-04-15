#pragma once

/*
6.2.2 CA ���ʋL�q�q�iCA identifier descriptor�j
CA ���ʋL�q�q�i�\6�|3 �Q�Ɓj�́A����̃u�[�P�A�T�[�r�X�A�C�x���g�A���邢�̓R��
�|�[�l���g�������M�V�X�e���Ɋ֌W���Ă��邩�ǂ����������A����Ɍ����M��������
�iCA_system_id�j�Ō����M�V�X�e���̎�ʂ������B

CA_identifier_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	for (i=0;i<N;i++){
		CA_system_id			16 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
CA_system_id�i�����M�������ʁj�F����16 �r�b�g�̃t�B�[���h�́ACA �V�X�e������
�ʂ���B���̃t�B�[���h�l�̊����ẮA�W�����@�ւ̋K��ɂ��B�i�t�^M �Q�Ɓj
*/

#include "../../../Common/Util.h"

class CCAIdentifierDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<WORD> CA_system_id_List;

public:
	CCAIdentifierDesc(void);
	~CCAIdentifierDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
