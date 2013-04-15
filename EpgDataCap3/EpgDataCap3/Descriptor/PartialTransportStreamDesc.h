#pragma once

/*
8.2.8.3.1 �p�[�V�����g�����X�|�[�g�X�g���[���L�q�q
(Partial Transport Stream descriptor)
���̋L�q�q�́A�p�[�V�����g�����X�|�[�g�X�g���[�����L�^���邽�߂ɕK�v�Ƃ�����
��Ƃ��ėp������B(�\8-2-10 �Q��)

partial_transport_stream_descriptor(){
	descriptor_tag						8 uimsbf
	descriptor_length					8 uimsbf
	reserved_future_use					2 bslbf
	peak_rate							22 uimsbf
	reserved_future_use					2 bslbf
	minimum_overall_smoothing_rate		22 uimsbf
	reserved_future_use					2 bslbf
	maximum_overall_smoothing_buffer	14 uimsbf
}

descriptor_tag�i�L�q�q�^�O�j�F�L�q�q�^�O��8 �r�b�g�̃t�B�[���h�ŁA�e�L�q�q�����ʂ�
��BMPEG-2 �K�i�ɏ]�����Ӗ��ł̂����̒l�́AISO/IEC 13818-1(21)�ɋL�ڂ���Ă���B
descriptor_length�i�L�q�q���j�F�L�q�q����8 �r�b�g�̃t�B�[���h�ŁA���̃t�B�[���h��
����ɑ����L�q�q�̃f�[�^�����̑S�o�C�g�����K�肷��B
peak_rate (�s�[�N���[�g)�F�ő�u���g�����X�|�[�g�p�P�b�g���[�g�i���Ȃ킿�A188 �o
�C�g��2 �̘A������g�����X�|�[�g�X�g���[���p�P�b�g�̃X�^�[�g���Ԃ̎��ԊԊu�ŏ�
�Z�������̂ł���j�B���̃s�[�N���[�g�̏�������Ȃ��Ƃ��K�肳���ׂ��ł���B����
22 �r�b�g�t�B�[���h��400 �r�b�g�^�b�P�ʂ̐��̐����ŃR�[�h�������B
minimum_overall_smoothing_rate (�ŏ����X���[�W���O���[�g)�F�S�g�����X�|�[�g�X
�g���[���̍ŏ����X���[�W���O�o�b�t�@�̃��[�N���[�g�i���ׂẴp�P�b�g���܂܂��j�B
����22 �r�b�g�t�B�[���h��400 �r�b�g�^�b�P�ʂ̐��̐����ŃR�[�h�������B�l
0x3FFFFF �͍ŏ��X���[�W���O���[�g������`�ł��邱�Ƃ������̂ɗp������B
maximum_overall_smoothing_buffer (�ő呍�X���[�W���O�o�b�t�@)�F�S�g�����X�|�[
�g�X�g���[���̍ő�X���[�W���O�o�b�t�@�T�C�Y�i���ׂẴp�P�b�g���܂܂��j�B����
14 �r�b�g�t�B�[���h��1byte �P�ʂ̐��̐����ŃR�[�h�������B�l0x3FFF �͍ő�X��
�[�W���O�o�b�t�@�T�C�Y������`�ł��邱�Ƃ������̂ɗp������B
*/

#include "../../../Common/Util.h"

class CPartialTransportStreamDesc
{
public:
	BYTE descriptor_tag;
	BYTE descriptor_length;
	DWORD peak_rate;
	DWORD minimum_overall_smoothing_rate;
	WORD maximum_overall_smoothing_buffer;
public:
	CPartialTransportStreamDesc(void);
	~CPartialTransportStreamDesc(void);

	BOOL Decode( BYTE* data, DWORD dataSize, DWORD* decodeReadSize );
};
