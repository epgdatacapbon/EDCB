#pragma once

/*
6.2.8 �����N�L�q�q�iLinkage descriptor�j
�����N�L�q�q�i�\6�|13 �Q�Ɓj�́ASI �V�X�e���ɋL�ڂ���Ă��邠�����̂��̂Ɋ֘A
�����ǉ����������҂��v�������ꍇ�ɒ񋟂����T�[�r�X�����ʂ���B�f�[�^�\������
�����郊���N�L�q�q�̈ʒu�Œǉ���񂪗��p�\�Ȃ��̂������B���Ƃ��΁ANIT ���̃���
�N�L�q�q�̓l�b�g���[�N�ɂ��Ă̒ǉ�����񋟂���T�[�r�X���w���ABAT ���ł́A�u
�[�P���ɂ��ẴT�[�r�X���Ƀ����N����B
CA ��փT�[�r�X�́A�����N�L�q�q���g�p���邱�Ƃł����ʂł���BCA ��SI �V�X�e��
�ɋL�ڂ���Ă������̂��̂ւ̃A�N�Z�X�����ۂ����ꍇ�ɂ́A���̑�փT�[�r�X����M
�@�ɂ���Ď����I�ɑI�������B

linkage_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	transport_stream_id		16 uimsbf
	original_network_id		16 uimsbf
	service_id				16 bslbf
	linkage_type			8 uimsbf
	for (i=0;i<N;i++){
		private_data_byte		8 bslbf
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
transport_stream_id�i�g�����X�|�[�g�X�g���[�����ʁj�F�����16 �r�b�g�̃t�B�[���h
�ŁA�w������Ă�����T�[�r�X���܂܂��g�����X�|�[�g�X�g���[�������ʂ���B
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F����16 �r�b�g�̃t�B�[���h�́A
�w������Ă�����T�[�r�X�̌��̕��z�V�X�e���̃l�b�g���[�N���ʂ��K�肷�郉�x����
����������B
service_id�i�T�[�r�X���ʁj�F�����16 �r�b�g�̃t�B�[���h�ŁA���̃g�����X�|�[�g�X�g
���[�����̏��T�[�r�X�����j�[�N�Ɏ��ʂ���B�T�[�r�X���ʂ́A�Ή�����v���O�����}
�b�v�Z�N�V�������̕����ԑg�ԍ����ʁiprogram_number�j�ɓ������B�����N��ʂ̒l��
0x04 �̏ꍇ�A�T�[�r�X���ʂ̃t�B�[���h�͈Ӗ����������A0x0000 �ɐݒ肳���B
linkage_type�i�����N��ʁj�F�����8 �r�b�g�̃t�B�[���h�ŁA�����N�̎�ʂȂǂ̏��
�������B�i�\6�|14 �Q�Ɓj
private_data_byte�i�v���C�x�[�g�f�[�^�j�F�����8 �r�b�g�̃t�B�[���h�ŁA�ʂɒ�`
���ꂽ�l������
*/

#include "../../../Common/Util.h"

class CLinkageDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	WORD transport_stream_id;
	WORD original_network_id;
	WORD service_id;
	WORD linkage_type;
	BYTE private_data_byteLength;
	BYTE* private_data_byte;
public:
	CLinkageDesc(void);
	~CLinkageDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
