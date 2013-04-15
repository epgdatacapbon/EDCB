#ifndef __OAUTH_UTIL_H__
#define __OAUTH_UTIL_H__

#include "../../Common/StringUtil.h"

BOOL GetTimeStamp(wstring& timeStamp);
BOOL CreateSignatureHMACSHA1(wstring src, wstring secretKey, wstring& signature);

//Unicode��UTF8�ɕϊ�����URL�G���R�[�h����
BOOL UrlEncodeUTF8(LPCWSTR src, DWORD srcSize, wstring& dest);
//Unicode��UTF8�ɕϊ�����URL�G���R�[�h����
BOOL UrlEncodeUTF8(LPCWSTR src, DWORD srcSize, string& dest);
//URL�f�R�[�h���s����UTF8��Unicode�ɕϊ�����
BOOL UrlDecodeUTF8(LPCSTR src, DWORD srcSize, wstring& dest);
//URL�f�R�[�h���s����UTF8��Unicode�ɕϊ�����
BOOL UrlDecodeUTF8(LPCWSTR src, DWORD srcSize, wstring& dest);

#endif
