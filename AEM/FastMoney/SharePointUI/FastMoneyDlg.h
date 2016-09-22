#pragma once
#include "Resource.h"

// CFastMoneyDlg dialog

class CFastMoneyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFastMoneyDlg)

public:
	CFastMoneyDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFastMoneyDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
