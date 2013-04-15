// RecName_Macro.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"


#include "RecName_PlugIn.h"
#include "SettingDlg.h"
#include "ConvertMacro.h"
#include "ConvertMacro2.h"
#include <tchar.h>

#define PLUGIN_NAME L"�}�N�� PlugIn"

extern HINSTANCE g_instance;

//PlugIn�̖��O���擾����
//name��NULL���͕K�v�ȃT�C�Y��nameSize�ŕԂ�
//�ʏ�nameSize=256�ŌĂяo��
//�߂�l
// TRUE�i�����j�AFALSE�i���s�j
//�����F
// name						[OUT]����
// nameSize					[IN/OUT]name�̃T�C�Y(WCHAR�P��)
BOOL WINAPI GetPlugInName(
	WCHAR* name,
	DWORD* nameSize
	)
{
	if( name == NULL ){
		if( nameSize == NULL ){
			return FALSE;
		}else{
			*nameSize = (DWORD)wcslen(PLUGIN_NAME)+1;
		}
	}else{
		if( nameSize == NULL ){
			return FALSE;
		}else{
			if( *nameSize < (DWORD)wcslen(PLUGIN_NAME)+1 ){
				*nameSize = (DWORD)wcslen(PLUGIN_NAME)+1;
				return FALSE;
			}else{
				wcscpy_s(name, *nameSize, PLUGIN_NAME);
			}
		}
	}
	return TRUE;
}

//PlugIn�Őݒ肪�K�v�ȏꍇ�A�ݒ�p�̃_�C�A���O�Ȃǂ�\������
//�����F
// parentWnd				[IN]�e�E�C���h�E
void WINAPI Setting(
	HWND parentWnd
	)
{
	WCHAR dllPath[512] = L"";
	GetModuleFileName(g_instance, dllPath, 512);

	wstring iniPath = dllPath;
	iniPath += L".ini";

	WCHAR buff[1024] = L"";
	GetPrivateProfileString(L"SET", L"Macro", L"$Title$.ts", buff, 1024, iniPath.c_str());

	CSettingDlg dlg;
	dlg.macro = buff;
	if( dlg.CreateSettingDialog(g_instance, parentWnd) == IDOK ){
		WritePrivateProfileString(L"SET", L"Macro", dlg.macro.c_str(), iniPath.c_str());
	}
}

//���͂��ꂽ�\��������ɁA�^�掞�̃t�@�C�������쐬����i�g���q�܂ށj
//recName��NULL���͕K�v�ȃT�C�Y��recNamesize�ŕԂ�
//�ʏ�recNamesize=256�ŌĂяo��
//�߂�l
// TRUE�i�����j�AFALSE�i���s�j
//�����F
// info						[IN]�\����
// recName					[OUT]����
// recNamesize				[IN/OUT]name�̃T�C�Y(WCHAR�P��)
BOOL WINAPI ConvertRecName(
	PLUGIN_RESERVE_INFO* info,
	WCHAR* recName,
	DWORD* recNamesize
	)
{
	if( recNamesize == NULL ){
		return FALSE;
	}
	WCHAR dllPath[512] = L"";
	GetModuleFileName(g_instance, dllPath, 512);

	wstring iniPath = dllPath;
	iniPath += L".ini";

	WCHAR buff[1024] = L"";
	GetPrivateProfileString(L"SET", L"Macro", L"$Title$.ts", buff, 1024, iniPath.c_str());

	wstring convert = L"";
	CConvertMacro convertMacro;
	BOOL ret = convertMacro.Convert(buff, info, convert);
	if( recName == NULL ){
		*recNamesize = (DWORD)convert.size()+1;
	}else{
		if( *recNamesize < (DWORD)convert.size()+1 ){
			*recNamesize = (DWORD)convert.size()+1;
			ret = FALSE;
		}else{
			wcscpy_s(recName, *recNamesize, convert.c_str());
		}
	}

	return ret;
}

//���͂��ꂽ�\��������ɁA�^�掞�̃t�@�C�������쐬����i�g���q�܂ށj
//recName��NULL���͕K�v�ȃT�C�Y��recNamesize�ŕԂ�
//�ʏ�recNamesize=256�ŌĂяo��
//�߂�l
// TRUE�i�����j�AFALSE�i���s�j
//�����F
// info						[IN]�\����
// epgInfo					[IN]�ԑg���iEPG�\��Ŕԑg��񂪑��݂��鎞�A���݂��Ȃ��ꍇ��NULL�j
// recName					[OUT]����
// recNamesize				[IN/OUT]name�̃T�C�Y(WCHAR�P��)
BOOL WINAPI ConvertRecName2(
	PLUGIN_RESERVE_INFO* info,
	EPG_EVENT_INFO* epgInfo,
	WCHAR* recName,
	DWORD* recNamesize
	)
{
	if( recNamesize == NULL ){
		return FALSE;
	}
	WCHAR dllPath[512] = L"";
	GetModuleFileName(g_instance, dllPath, 512);

	wstring iniPath = dllPath;
	iniPath += L".ini";

	WCHAR buff[1024] = L"";
	GetPrivateProfileString(L"SET", L"Macro", L"$Title$.ts", buff, 1024, iniPath.c_str());

	wstring convert = L"";
	CConvertMacro2 convertMacro;
	BOOL ret = convertMacro.Convert(buff, info, epgInfo, convert);
	if( recName == NULL ){
		*recNamesize = (DWORD)convert.size()+1;
	}else{
		if( *recNamesize < (DWORD)convert.size()+1 ){
			*recNamesize = (DWORD)convert.size()+1;
			ret = FALSE;
		}else{
			wcscpy_s(recName, *recNamesize, convert.c_str());
		}
	}

	return ret;
}
