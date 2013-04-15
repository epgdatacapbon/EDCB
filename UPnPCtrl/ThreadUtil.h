#ifndef __MULTI_PLATFORM_THREAD_UTIL_H__
#define __MULTI_PLATFORM_THREAD_UTIL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef void* MP_THREAD_HANDLE;
typedef void* MP_LOCK_HANDLE;

#ifdef _WIN32
typedef unsigned int (__stdcall *MP_THREAD_FUNC)(void* param);
#else
//Linux�n
typedef void* (*MP_THREAD_FUNC)(void* param);
#endif

//�r������p�̃n���h�����쐬����
//Windows�ł�CreateEvent
//Linux�n��pthread_mutex_init
//�߂�l�F�n���h���A�G���[��NULL
MP_LOCK_HANDLE MP_LOCK_CreateHandle(
	void
);

//�n���h���̉��
//�����handle��NULL��
//Windows�ł�CloseHandle
//Linux�n��pthread_mutex_destroy
void MP_LOCK_CloseHandle(
	MP_LOCK_HANDLE* handle				//[IN]MP_LOCK_CreateHandle�̖߂�l
);

//�r������p��Lock����
//Windows�ł�WaitForSingleObject
//Linux�n��pthread_mutex_lock
//�߂�l�F0�ȏ�Ő����A0�����ŃG���[
int MP_LOCK_Lock(
	MP_LOCK_HANDLE handle				//[IN]MP_LOCK_CreateHandle�̖߂�l
);

//�r������p��UnLock����
//Windows�ł�SetEvent
//Linux�n��pthread_mutex_unlock
//�߂�l�F0�ȏ�Ő����A0�����ŃG���[
int MP_LOCK_UnLock(
	MP_LOCK_HANDLE handle				//[IN]MP_LOCK_CreateHandle�̖߂�l
);


//�ʃX���b�h�Ŋ֐������s����
//Windows�ł�_beginthreadex
//Linux�n��pthread_create
//�߂�l�F�n���h���A�G���[��NULL
MP_THREAD_HANDLE MP_THREAD_BegineThread(
	MP_THREAD_FUNC func,							//[IN]�V�K�X���b�h�̎��s���N�����郋�[�`��
	void* param							//[IN]�V�K�X���b�h�ɓn��������
);

//�X���b�h�̏I����҂��J������������i�^�C���A�E�g�͂Ȃ��j
//�L�����Z�������͂��炩���ߍs���Ă�������
//Windows�ł�WaitForSingleObject
//Linux�n��pthread_join
//�I����handle��NULL��
void MP_THREAD_WaitEndThread(
	MP_THREAD_HANDLE* handle			//[IN]MP_THREAD_BegineThread�̖߂�l
);

//Sleep���s��
//Windows�ł�Sleep
//Linux�n��nanosleep
void MP_Sleep(
	int msec			//[IN]msec�P��
);

#ifdef __cplusplus
}
#endif

#endif
