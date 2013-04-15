#pragma once

/*
8.2.8.3.2 �l�b�g���[�N���ʋL�q�q�iNetwork_Identification_descriptor�j
���̋L�q�q�́A�p�[�V�����g�����X�|�[�g�X�g���[�������o���ꂽ���̃l�b�g���[�N
�𖾊m�ɂ���ׂɗp������BSIT �̓`�����L�q���[�v�ɂ݂̂ɑ}�������B�i�\8-2-11
�Q�Ɓj

network_identification_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	country_code			24 bslbf
	media_type				16 bslbf
	network_id				16 uimsbf
	for(i=0; i<N; i++){
		private_data		8 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
country_code�i���R�[�h�j�F����24 �r�b�g�̃t�B�[���h�́AISO3166 �ŋK�肳���A���t�@�x�b
�g3 �����R�[�h���g�p���č�����\�킷�B���̋L�q�q�Ɏg�p���ꂽ�ꍇ�́A�p�[�V�����g�����X
�|�[�g�X�g���[���̐������ꂽ���z�V�X�e���̍���\�킷�B�e�����́AISO8859-1 �ɏ]����8 �r
�b�g�ŕ���������A���̏���24 �r�b�g�t�B�[���h�ɑ}�������B���{��3 �����R�[�h�́uJPN�v
�ł���A���̂悤�ɕ����������B
�u0100 1010 0101 0000 0100 1110�v
media_type�i���f�B�A���ށj�F����16 �r�b�g�̃t�B�[���h�́A�A���t�@�x�b�g2 �������}����
��A����2 �����ɂ���ă��f�B�A�̃^�C�v��\�킷�B���̋L�q�q�Ɏg�p���ꂽ�ꍇ�́A�p�[�V��
���g�����X�|�[�g�X�g���[���̐������ꂽ���z�V�X�e���̃��f�B�A�^�C�v��\�킷�B�e�����́A
ISO8859-1 �ɏ]����8 �r�b�g�ŕ���������A���̏���16 �r�b�g�t�B�[���h�ɑ}�������B���f
�B�A�̎�ނ́A���L�ɂ��B
network_id�i�l�b�g���[�N���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA�p�[�V�����g�����X�|�[�g
�X�g���[���̐������ꂽ���z�V�X�e���̃l�b�g���[�N���ʂ̒l���L�q�����B�I���W�i���̕��z
�V�X�e���ł́ANIT �ɂ��̒l���L�q����Ă���A���̃t�B�[���h�l�̊��蓖�Ă͕W�����@�ւ̎w
��ɂ��B
private_data�i�v���C�x�[�g�f�[�^�j�F�����8�~N �r�b�g�̃t�B�[���h�ŁA�ʂɒ�`���ꂽ�l
�����B
*/

#include "../../../Common/Util.h"

class CNetworkIdentification
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	CHAR country_code[4];
	WORD media_type;
	WORD network_id;
	BYTE private_dataLength;
	BYTE* private_data;
public:
	CNetworkIdentification(void);
	~CNetworkIdentification(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
