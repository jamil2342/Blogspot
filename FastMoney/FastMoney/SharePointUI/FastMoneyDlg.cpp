// FastMoneyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FastMoneyDlg.h"
#include "afxdialogex.h"


// CFastMoneyDlg dialog

IMPLEMENT_DYNAMIC(CFastMoneyDlg, CDialogEx)

CFastMoneyDlg::CFastMoneyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFastMoneyDlg::IDD, pParent)
{

}

CFastMoneyDlg::~CFastMoneyDlg()
{
}

void CFastMoneyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFastMoneyDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFastMoneyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFastMoneyDlg message handlers


void CFastMoneyDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
