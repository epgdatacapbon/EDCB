#pragma once

#include "resource.h"

//�T�[�r�X����p�̃��C��
void WINAPI service_main(DWORD dwArgc, LPTSTR *lpszArgv);

//�T�[�r�X����̃R�}���h�̃R�[���o�b�N
DWORD WINAPI service_ctrl(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext);

//�T�[�r�X�̃X�e�[�^�X�ʒm�p
BOOL SendStatusScm(int iState, int iExitcode, int iProgress);

//���C������
//�����F
// serviceFlag			[IN]�T�[�r�X�Ƃ��Ă̋N�����ǂ���
void StartMain(
	BOOL serviceFlag
	);

//���C��������~
void StopMain();
