#pragma once

/*
6.2.32 ������M�L�q�q�iPartial reception descriptor�j
������M�L�q�q�́A�n��`���H�̕�����M�K�w�œ`������Ă���T�[�r�X���ʂ��L�q��
��B�\6�|64 �Q�ƁB

partial_reception_descriptor(){
	descriptor_tag		8 uimsbf
	descriptor_length	8 uimsbf
	for(i=0; i<N; i++){
		service_id			16 uimsbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA������M�K�w�œ`������
����T�[�r�X�̃T�[�r�X���ʂ������B�T�[�r�X���ʂ́A�Ή�����v���O�����}�b�v�Z�N
�V�������̕����ԑg�ԍ����ʁiprogram_number�j�ɓ������B

*/

#include "../../../Common/Util.h"

class CPartialReceptionDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	vector<WORD> service_idList;
public:
	CPartialReceptionDesc(void);
	~CPartialReceptionDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
