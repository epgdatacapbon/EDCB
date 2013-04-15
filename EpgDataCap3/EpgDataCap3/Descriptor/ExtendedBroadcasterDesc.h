#pragma once

/*
6.2.43 �g���u���[�h�L���X�^�L�q�q�iExtended broadcaster descriptor�j
�g���u���[�h�L���X�^�L�q�q�́A�n��u���[�h�L���X�^���ʂȂǂ̊g���u���[�h�L���X
�^���ʏ����w�肵�A���̊g���u���[�h�L���X�^��A���l�b�g���[�N�̃u���[�h�L���X�^
�Ƃ̊֘A�Â����s���B�\6-83 �Q�ƁB

extended_broadcaster_descriptor(){
	descriptor_tag						8 uimsbf
	descriptor_length					8 uimsbf
	broadcaster_type					4 uimsbf
	reserved_future_use					4 bslbf
	if ( broadcaster_type == 0x1 ) {
		terrestrial_broadcaster_id			16 uimsbf
		number_of_affiliation_id_loop		4 uimsbf
		number_of_broadcaster_id_loop		4 uimsbf
		for( i=0; i<N1; i++ ) {
			affiliation_id						8 uimsbf
		}
		for( j=0; j<N2; j++ ) {
			original_network_id					16 uimsbf
			broadcaster_id						8 uimsbf
		}
		for( k=0; k<N3; k++ ) {
			private_data_byte					8 bslbf
		}
	}else if ( broadcaster_type == 0x2 ) {
		terrestrial_sound_broadcaster_id	16 uimsbf
		number_of_sound_broadcast_affiliation_id_loop	4 uimsbf
		number_of_broadcaster_id_loop		4 uimsbf
		for( i=0; i<N1; i++ ) {
			sound_broadcast_affiliation_id		8 uimsbf
		}
		for( j=0; j<N2; j++ ) {
			original_network_id					16 uimsbf
			broadcaster_id						8 uimsbf
		}
		for( k=0; k<N3; k++ ) {
			private_data_byte					8 bslbf
		}
	}else{
		for(i=0;i<N;i++){
			reserved_future_use					8 bslbf
		}
	}
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
broadcaster_type�i�u���[�h�L���X�^��ʁj�F����͂S�r�b�g�̃t�B�[���h�ŕ\6-84 �ɏ]
�������������B
terrestrial_broadcaster_id(�n��u���[�h�L���X�^����)�F����͂P�U�r�b�g�̃t�B�[���h�ŁA
���Y�t�B�[���h�ŋL�ڂ���n��u���[�h�L���X�^�����ʂ���B
number_of_affiliation_id_loop�i�n�񎯕ʃ��[�v���j�F����͂S�r�b�g�̃t�B�[���h�ŁA
�㑱�̌n�񎯕ʂ̃��[�v���������B
number_of_broadcaster_id_loop�i�u���[�h�L���X�^���ʃ��[�v���j�F����͂S�r�b�g�̃t
�B�[���h�ŁA�㑱�̃u���[�h�L���X�^���ʃ��[�v�̃��[�v���������B
affiliation_id�i�n�񎯕ʁj�F����͂W�r�b�g�̃t�B�[���h�ŁA���Y�n��u���[�h�L���X�^
���ʂ��A�ǂ̌n��Ɋ܂܂�邩�����ʂ��邽�߂ɗp������B
original_network_id�i�I���W�i���l�b�g���[�N���ʁj�F���̂P�U�r�b�g�̃t�B�[���h�́A
���̕��z�V�X�e���̃l�b�g���[�N���ʂ��K�肷�郉�x���̖���������B
broadcaster_id�i�u���[�h�L���X�^���ʁj�F����͂W�r�b�g�̃t�B�[���h�ŁA���̃I���W
�i���l�b�g���[�N���̃u���[�h�L���X�^�����ʂ���B
terrestrial_sound_broadcaster_id(�n�㉹���u���[�h�L���X�^����)�F����͂P�U�r�b�g��
�t�B�[���h�ŁA���Y�t�B�[���h�ŋL�ڂ���n�㉹���u���[�h�L���X�^�����ʂ���B
number_of_sound_broadcast_affiliation_id_loop�i���������n�񎯕ʃ��[�v���j�F�����
�S�r�b�g�̃t�B�[���h�ŁA�㑱�̉��������n�񎯕ʂ̃��[�v���������B
number_of_sound_broadcaster_id_loop�i�u���[�h�L���X�^���ʃ��[�v���j�F����͂S�r
�b�g�̃t�B�[���h�ŁA�㑱�̒n�㉹���u���[�h�L���X�^���ʃ��[�v�̃��[�v���������B
sound_broadcast_affiliation_id�i���������n�񎯕ʁj�F����͂W�r�b�g�̃t�B�[���h�ŁA
���Y�n�㉹���u���[�h�L���X�^���ʂ��A�ǂ̉��������n��Ɋ܂܂�邩�����ʂ��邽�߂�
�p������B

*/

#include "../../../Common/Util.h"

class CExtendedBroadcasterDesc
{
public:
	typedef struct _BROADCAST_DATA{
		WORD original_network_id;
		BYTE broadcaster_id;
	} BROADCAST_DATA;
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE broadcaster_type;
	WORD terrestrial_broadcaster_id;
	BYTE number_of_affiliation_id_loop;
	BYTE number_of_broadcaster_id_loop;
	vector<BYTE> affiliation_idList;
	vector<BROADCAST_DATA> broadcastList;
	WORD terrestrial_sound_broadcaster_id;
	BYTE number_of_sound_broadcast_affiliation_id_loop;
	vector<BYTE> sound_broadcast_affiliation_idList;
public:
	CExtendedBroadcasterDesc(void);
	~CExtendedBroadcasterDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
