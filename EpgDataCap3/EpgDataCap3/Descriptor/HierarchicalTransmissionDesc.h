#pragma once

/*
6.2.22 �K�w�`���L�q�q (Hierarchical transmission descriptor�j
�K�w�`���L�q�q�i�\6�|37 �Q�Ɓj�́A�ԑg���e���K�w�����ē`������ꍇ�́A�K�w����
���X�g���[���Ԃ̊֌W�������̂ɗp������B

hierarchical_transmission_descriptor(){
	descriptor_tag			8 uimsbf
	descriptor_length		8 uimsbf
	reserved_future_use		7 bslbf
	quality_level			1 bslbf
	reserved_future_use		3 bslbf
	reference_PID			13 uimsbf
}

broadcasting_flag�i�����^�������ʁj�F�����2 �r�b�g�̃t�B�[���h�ŁA�\6�|35 �ɏ]
���ĕ����^������������B
broadcasting_identifier�i�����̕W��������ʁj�F�����6 �r�b�g�̃t�B�[���h�ŁA�\6
�|36 �ɏ]���ĕ����̕W�������������B
quality_level�i�K�w���x���j�F�K�w�������i�K�������B�K�w�\���́AHQ�ALQ ��2 �i�K��
���A�K�w���x���̒l��1 �̏ꍇ�A���̃X�g���[���͍��K�w�ł��邱�Ƃ������B�K�w���x��
�̒l��0 �̏ꍇ�A���̃X�g���[���͒�K�w�ł��邱�Ƃ������B
reference_PID�i�Q�Ɛ�PID�j�F�K�w�\���������Ă��邷�ׂẴX�g���[���ɂ��āA�Q��
��̃G�������^���[�X�g���[����PID �������B

*/

#include "../../../Common/Util.h"

class CHierarchicalTransmissionDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	BYTE quality_level;
	WORD reference_PID;
public:
	CHierarchicalTransmissionDesc(void);
	~CHierarchicalTransmissionDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
