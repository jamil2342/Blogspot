// FastMoneyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FastMoneyDlg.h"
#include "afxdialogex.h"
#include "Globals.h"

// CFastMoneyDlg dialog

IMPLEMENT_DYNAMIC(CFastMoneyDlg, CDialogEx)

CFastMoneyDlg::CFastMoneyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFastMoneyDlg::IDD, pParent)
{

}

CFastMoneyDlg::~CFastMoneyDlg()
{
}

BOOL CFastMoneyDlg::OnInitDialog()
{
	loadDisk();

	////AfxMessageBox(a.url.c_str());
	//SetDlgItemText(IDC_EDIT1, a.url.c_str());
	//string str = "" + a.refreshTime;
	////AfxMessageBox(a.url.c_str());
	//SetDlgItemText(IDC_EDIT1, str.c_str());
	SetDlgItemText(IDC_EDIT1, "http://podcast.cnbc.com/mmpodcast/fastmoney.xml");
	SetDlgItemText(IDC_EDIT2, "60");

	return TRUE;
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
	//emptyDisk();
	CString str;

	GetDlgItemText(IDC_EDIT1,str);
	a.url = (LPCTSTR)str;
	AfxMessageBox((LPCTSTR)str);
	GetDlgItemText(IDC_EDIT2, str);
	a.refreshTime = atoi(str);
	writeDisk();




	
	CDialogEx::OnOK();
}
