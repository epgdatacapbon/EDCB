#ifndef __UPNP_SSDP_UTIL_H__
#define __UPNP_SSDP_UTIL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include "SortListUtil.h"
#include "UpnpStructDef.h"

typedef void* UPNP_SERVER_HANDLE;
typedef void* UPNP_MSEARCH_HANDLE;

typedef enum{
	SSDP_unknown        = 0x0000,
	SSDP_alive			= 0x0001,	//alive�ʒm notifyParam�͒ʒm���e(UPNP_SSDP_NOTIFY_INFO*)
	SSDP_byebye			= 0x0002,	//byebye�ʒm notifyParam�͒ʒm���e(UPNP_SSDP_NOTIFY_INFO*)
	SSDP_update			= 0x0004,	//update�ʒm notifyParam�͒ʒm���e(UPNP_SSDP_NOTIFY_INFO*)
	SSDP_MSearch		= 0x0010,	//M-Search�̌��� notifyParam�͒ʒm���e(UPNP_MSEARCH_RESPONSE_INFO*)
	SSDP_MSearchEnd		= 0x0020,	//M-Search�̊��� notifyParam��UPNP_MSEARCH_HANDLE
} SSDP_NOTIFY_STATUS;


//SSDP��Notify�ʒm�p�R�[���o�b�N�֐�
typedef void (*UPNP_SSDP_CALLBACK)(
	SSDP_NOTIFY_STATUS notifyType,		//[IN]ssdp�̎��
	void* notifyParam,					//[IN]NOTIFY�̓��e
	void* param							//[IN]���[�U�[�w��̃p�����[�^
);

typedef int (*UPNP_MSEARCH_REQUEST_CALLBACK)(
	UPNP_MSEARCH_REQUEST_INFO* requestParam,	//[IN]NOTIFY�̓��e
	void* param,								//[IN]���[�U�[�w��̃p�����[�^
	SORT_LIST_HANDLE resDeviceList				//[OUT]���X�|���X�Ƃ��ĕԂ��f�o�C�X�̏�������@�L�[�FUPNP_MSEARCH_RES_DEV_INFO��uuid �v�f�FUPNP_MSEARCH_RES_DEV_INFO*
);

//�n���h���̍쐬
//�߂�l�F�n���h���A�G���[��NULL
UPNP_SERVER_HANDLE UPNP_SERVER_CreateHandle(
	UPNP_SSDP_CALLBACK ssdpCallBack,	//[IN]SSDP��Notify�ʒm�p�R�[���o�b�N
	void* ssdpCallBackParam,			//[IN]SSDP��Notify�ʒm�p�R�[���o�b�N�ďo���ɓ����p�����[�^�[
	UPNP_MSEARCH_REQUEST_CALLBACK msearchCallBack,	//[IN]SSDP��M-SEARCH���N�G�X�g�ʒm�p�R�[���o�b�N
	void* msearchCallBackParam			//[IN]SSDP��M-SEARCH���N�G�X�g�ʒm�p�R�[���o�b�N�ďo���ɓ����p�����[�^�[
);

//�n���h���̉��
//�����handle��NULL��
void UPNP_SERVER_CloseHandle(
	UPNP_SERVER_HANDLE* handle			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
);

//UPnP�T�[�o�[�̋N��
//�߂�l�F�G���[�R�[�h
int UPNP_SERVER_Start(
	UPNP_SERVER_HANDLE handle			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
);

//UPnP�T�[�o�[�̒�~
//�߂�l�F�G���[�R�[�h
int UPNP_SERVER_Stop(
	UPNP_SERVER_HANDLE handle			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
);

//Notify�p��device��service��o�^����
int UPNP_SERVER_AddNotifyInfo(
	UPNP_SERVER_HANDLE handle,			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
	const char* uuid,					//[IN]uuid�uuuid:�v�͏Ȃ�
	const char* urn,					//[IN]urn�uurn:�v���܂�
	int locationPort,					//[IN]Location�̃|�[�g
	const char* locationUri				//[IN]Location�́uhttp://ip:port�v�����̕���(�u/�v����n�܂�)
);

//Notify�p��device��service�̓o�^����������
int UPNP_SERVER_RemoveNotifyInfo(
	UPNP_SERVER_HANDLE handle,			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
	const char* uuid					//[IN]uuid�uuuid:�v�͏Ȃ�
);

//Notify�p��device��service�̑S�o�^����������
int UPNP_SERVER_ClearNotifyInfo(
	UPNP_SERVER_HANDLE handle			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
);

//M-Search �@��̌��������s�i�����j
//�߂�l�F�n���h���A�G���[��NULL
UPNP_MSEARCH_HANDLE UPNP_MSearch_Exec(
	UPNP_SERVER_HANDLE handle,			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
	const char* searchTarget,			//[IN]���s����ST�̒l�i�����L�[�j
	short mx,							//[IN]���s����MX�̒l(�P�ʁF�b)�i�^�C���A�E�g�j
	SORT_LIST_HANDLE* resultList		//[OUT]�������ʂ̃��X�g�A�L�[�Fchar* ��UUID�A�v�f�FUPNP_MSEARCH_INFO*�@UPNP_MSearch_CloseHandle�ŊJ�����邳���
);

//M-Search �@��̌��������s�i�񓯊��j
//�������ʂ̓R�[���o�b�N�ł̒ʒm�̂�
//�߂�l�F�n���h���A�G���[��NULL
UPNP_MSEARCH_HANDLE UPNP_MSearch_ExecAsync(
	UPNP_SERVER_HANDLE handle,			//[IN]UPNP_SERVER_CreateHandle�̖߂�l
	const char* searchTarget,			//[IN]���s����ST�̒l�i�����L�[�j
	short mx							//[IN]���s����MX�̒l(�P�ʁF�b)�i�^�C���A�E�g�j
);

//M-Search�n���h���̉��
//�񓯊����s���͓���̃L�����Z���������
//�����handle��NULL��
void UPNP_MSearch_CloseHandle(
	UPNP_MSEARCH_HANDLE* handle			//[IN]UPNP_MSearch_Exec or UPNP_MSearch_ExecAsync�̖߂�l
);

//DDD(Device Description Document)�擾���s(����)
//�߂�l�F0�ȏ�Ő����A0�����ŃG���[
int UPNP_GetDDD_Exec(
	const char* location						//[IN]M-Search���ʂ�location
);

#ifdef __cplusplus
}
#endif

#endif
