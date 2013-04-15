#pragma once
#include "afxcmn.h"

#define TIMER_WAIT_SLEEP 100
// CQueryWaitDlg �_�C�A���O

class CQueryWaitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQueryWaitDlg)

public:
	CQueryWaitDlg(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CQueryWaitDlg();

	void SetRebootMode(){ m_bReboot = TRUE; };

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DIALOG_QUERY_WAIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DWORD dwCount;
	BOOL m_bReboot;

	DECLARE_MESSAGE_MAP()
public:
	CString msgText;
	CProgressCtrl waitProg;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCancel();
};
