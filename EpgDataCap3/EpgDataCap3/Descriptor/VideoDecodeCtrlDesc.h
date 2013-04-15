#pragma once

/*
6.2.30 �r�f�I�f�R�[�h�R���g���[���L�q�q�iVideo decode control descriptor�j
�r�f�I�f�R�[�h�R���g���[���L�q�q�i�\6-59 �Q�Ɓj�́A�������`�����x�ő��M�����
MPEG-I �s�N�`���ō\�������Î~�摜����M���邽�߁A�y�щf���t�H�[�}�b�g�̐؂��
���_�ɂ����ăX���[�Y�ȕ\�������邽�߂ɁA�r�f�I�f�R�[�h���R���g���[������ꍇ��
�g�p�����B

video_decode_control_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	still_picture_flag		1 bslbf
	sequence_end_code_flag	1 bslbf
	video_encode_format		4 bslbf
	reserved_future_use		2 bslbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
still_picture_flag�i�Î~��t���O�j�F����͂P�r�b�g�̃t�B�[���h�ŁA�u�P�v�̏ꍇ�́A
���̃R���|�[�l���g���Î~��iMPEG-I �s�N�`���j�ł��邱�Ƃ������B�u0�v�̏ꍇ�́A��
�̃R���|�[�l���g������ł��邱�Ƃ������B
sequence_end_code_flag�i�V�[�P���X�G���h�R�[�h�t���O�j�F�����1 �r�b�g�̃t�B�[���h
�ŁA���̃R���|�[�l���g���r�f�I�G���R�[�h�t�H�[�}�b�g�Ŏ������f���t�H�[�}�b�g�̏I
���_�ɂ����āA�V�[�P���X�G���h�R�[�h�iMPEG-2 Video �K�i�̏ꍇ�BMPEG-4 AVC �K�i
�̏ꍇ�̓G���h�E �I�u�E�V�[�P���XNAL ���j�b�g�B�ȉ����l�B�j�𑗐M����X�g���[����
���邩�ۂ��������B�u1�v�̏ꍇ�́A���̉f���X�g���[���̓V�[�P���X�G���h�R�[�h�����M
�����X�g���[���ł��邱�Ƃ������A�u0�v�̏ꍇ�́A�V�[�P���X�G���h�R�[�h�����M����
�Ȃ��X�g���[���ł��邱�Ƃ������B
video_encode_format�i�r�f�I�G���R�[�h�t�H�[�}�b�g�j�F�����4 �r�b�g�̃t�B�[���h�ŁA
�\6�|60 �ɏ]���Ă��̃R���|�[�l���g�̃G���R�[�h�t�H�[�}�b�g�������B

*/

#include "../../../Common/Util.h"

class CVideoDecodeCtrlDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE still_picture_flag;
	BYTE sequence_end_code_flag;
	BYTE video_encode_format;
public:
	CVideoDecodeCtrlDesc(void);
	~CVideoDecodeCtrlDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
