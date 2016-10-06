// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "Page1.h"
#include "bmpinfo.h"

#include "SharePointUI.h"
#include "CollectorInbound.h"

#include "svrListener.h"
#include "pubutility.h"
#include "PSDBDefines.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1 property page

IMPLEMENT_DYNCREATE(CPage1, CPropertyPage)

CPage1::CPage1(CSharePointInbound *pInbound) : CPropertyPage(CPage1::IDD)
, m_timeout(0)
, m_url4(_T(""))
, m_url5(_T(""))
, m_url6(_T(""))
, m_url7(_T(""))
, m_image_base_url(_T(""))
, m_url8(_T(""))
, m_url9(_T(""))
, m_url10(_T(""))
, m_url11(_T(""))
, m_url12(_T(""))
, m_url13(_T(""))
, m_url14(_T(""))
, m_url15(_T(""))
{
	m_pInbound = pInbound;
	ASSERT(m_pInbound);

	m_chg = false;
	m_selChg = false;

	//{{AFX_DATA_INIT(CPage1)
	m_name = m_pInbound->m_base.m_name;
	m_freq = m_pInbound->m_base.m_update_interval;
	m_timeout = m_pInbound->m_base.m_update_timeout;
	m_url1 = m_pInbound->m_base.m_szServiceUrl1;
	m_url2 = m_pInbound->m_base.m_szServiceUrl2;
	m_url3 = m_pInbound->m_base.m_szServiceUrl3;
	m_url4 = m_pInbound->m_base.m_szServiceUrl4;
	m_url5 = m_pInbound->m_base.m_szServiceUrl5;
	m_url6 = m_pInbound->m_base.m_szServiceUrl6;
	m_url7 = m_pInbound->m_base.m_szServiceUrl7;

	m_image_base_url = m_pInbound->m_base.m_imageBaseUrl;
	//}}AFX_DATA_INIT
}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 75);
	DDX_Text(pDX, IDC_FREQ, m_freq);
	DDV_MinMaxInt(pDX, m_freq, 5, 3600);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_NAME, m_editName);
	DDX_Control(pDX, IDC_FREQ, m_editFreq);
	DDX_Text(pDX, IDC_UTIMEOUT, m_timeout);
	DDV_MinMaxInt(pDX, m_timeout, 0, 32000);
	DDX_Control(pDX, IDC_UTIMEOUT, m_editTimeout);
	DDX_Control(pDX, IDC_EDIT_URL1, m_edit_url1);
	DDX_Control(pDX, IDC_EDIT_URL2, m_edit_url2);
	DDX_Control(pDX, IDC_EDIT_URL3, m_edit_url3);

	DDX_Text(pDX, IDC_EDIT_URL1, m_url1);
	DDV_MaxChars(pDX, m_url1, 75);

	DDX_Text(pDX, IDC_EDIT_URL2, m_url2);
	DDV_MaxChars(pDX, m_url2, 75);

	DDX_Text(pDX, IDC_EDIT_URL3, m_url3);
	DDV_MaxChars(pDX, m_url3, 75);
	DDX_Text(pDX, IDC_EDIT_URL4, m_url4);
	DDV_MaxChars(pDX, m_url4, 80);
	DDX_Text(pDX, IDC_EDIT_URL5, m_url5);
	DDV_MaxChars(pDX, m_url5, 80);
	DDX_Text(pDX, IDC_EDIT_URL6, m_url6);
	DDV_MaxChars(pDX, m_url6, 80);
	DDX_Text(pDX, IDC_EDIT_URL7, m_url7);
	DDV_MaxChars(pDX, m_url7, 80);
	DDX_Text(pDX, IDC_EDIT1, m_image_base_url);
	DDX_Text(pDX, IDC_EDIT_URL8, m_url8);
	DDX_Text(pDX, IDC_EDIT_URL9, m_url9);
	DDX_Text(pDX, IDC_EDIT_URL10, m_url10);
	DDX_Text(pDX, IDC_EDIT_URL11, m_url11);
	DDX_Text(pDX, IDC_EDIT_URL12, m_url12);
	DDX_Text(pDX, IDC_EDIT_URL13, m_url13);
	DDX_Text(pDX, IDC_EDIT_URL14, m_url14);
	DDX_Text(pDX, IDC_EDIT_URL15, m_url15);
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CPage1)
	ON_EN_CHANGE(IDC_FREQ, OnChangeFreq)
	ON_EN_CHANGE(IDC_NAME, OnChangeName)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_UTIMEOUT, &CPage1::OnEnChangeUtimeout)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

BOOL CPage1::OnApply() 
{
	if(!SaveItOff())
		return false;

	UpdateData(false);	// in case we flipped the hi-lo vals, OR didn't delete/add pubflds
	return CPropertyPage::OnApply();
}

BOOL CPage1::OnWizardFinish() 
{
	if(!SaveItOff())
		return false;
	
	return CPropertyPage::OnWizardFinish();
}

BOOL CPage1::SaveItOff()
{
	if(!UpdateData())
		return false;
	
	if (m_pInbound->VerifyName(m_name) == false)
	{
		m_name = oldInboundName;
		AfxMessageBox("Invalid name for collector.  You must enter a unique name for this collector.");
		m_editName.SetFocus();
		return false;
	}

	if ((m_freq < 5) || (m_freq > 3600))
		return FALSE;
	if ((m_timeout < 0) || (m_timeout > 32000))
		return FALSE;

	m_name.TrimLeft();
	m_name.TrimRight();

	if(m_name.IsEmpty())
	{
		AfxMessageBox("You must provide a name for the inbound.");
		m_editName.SetFocus();
		return false;
	}

	char temp[100];	sprintf(temp,m_name,100);
	bool bValidName = IsValidInboundName(temp);
	if (!bValidName)
	{
		AfxMessageBox("Collector names can not have \' or \" in them.");
		m_editName.SetFocus();
		return false;
	}

	if(m_name.Compare(m_pInbound->m_base.m_name))
	{
		m_chg = true;
		strncpy(m_pInbound->m_base.m_name,(LPCTSTR)m_name,75);
	}
	if(m_freq != m_pInbound->m_base.m_update_interval)
	{
		m_chg = true;
		m_pInbound->m_base.m_update_interval = m_freq;
	}
	if (m_timeout != m_pInbound->m_base.m_update_timeout)
	{
		m_chg = true;
		m_pInbound->m_base.m_update_timeout = m_timeout;
	}
	strncpy(m_pInbound->m_base.m_szServiceUrl1, (LPCTSTR)m_url1, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl2,(LPCTSTR)m_url2, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl3, (LPCTSTR)m_url3, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl4, (LPCTSTR)m_url4, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl5, (LPCTSTR)m_url5, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl6, (LPCTSTR)m_url6, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl7, (LPCTSTR)m_url7, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl8, (LPCTSTR)m_url8, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl9, (LPCTSTR)m_url9, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl10, (LPCTSTR)m_url10, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl11, (LPCTSTR)m_url11, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl12, (LPCTSTR)m_url12, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl13, (LPCTSTR)m_url13, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl14, (LPCTSTR)m_url14, 75);
	strncpy(m_pInbound->m_base.m_szServiceUrl15, (LPCTSTR)m_url15, 75);
	strcpy(m_pInbound->m_base.m_imageBaseUrl, (LPCTSTR)m_image_base_url);
	OutputDebugString("CPage3::title changed");

	m_chg = true;
	//strncpy_s(m_pInbound->m_base.m_szListTitle, _countof(m_pInbound->m_base.m_szListTitle), (LPCTSTR)m_listname, STANDARD_STRING);
	strcpy(m_pInbound->m_base.m_szListTitle, "Aem");
	strncpy_s(m_pInbound->m_base.m_szViewTitle, _countof(m_pInbound->m_base.m_szViewTitle), "", STANDARD_STRING);
	m_pInbound->m_base.m_tableCount = 1;
	m_pInbound->m_base.m_fieldCount = 0;
	FIELD_MAP_ITER iter = m_pInbound->m_colFlds.begin();
	while (iter != m_pInbound->m_colFlds.end())
	{
		delete (*iter).second;
		iter++;
	}
	m_pInbound->m_colFlds.clear();
	int i = 0;
	/// ###### Configurationchange 
	m_pInbound->m_colFlds[i++] = new CField("id", "Counter");
	m_pInbound->m_colFlds[i++] = new CField("url", "Text");
	m_pInbound->m_colFlds[i++] = new CField("image", "Text");	
	m_pInbound->m_colFlds[i++] = new CField("imagelocalfolder", "Text");
	//m_pInbound->m_colFlds[i++] = new CField("video", "Text");
	//m_pInbound->m_colFlds[i++] = new CField("videolocalfolder", "Text");
	m_pInbound->m_colFlds[i++] = new CField("headline", "Text");
	m_pInbound->m_colFlds[i++] = new CField("abstract", "Text");
	m_pInbound->m_colFlds[i++] = new CField("category", "Text");
	m_pInbound->m_colFlds[i++] = new CField("jcrcreated", "DateTime");
	m_pInbound->m_colFlds[i++] = new CField("cqlastmodified", "DateTime");
	m_pInbound->m_colFlds[i++] = new CField("newsappauthor", "Text");
	m_pInbound->m_colFlds[i++] = new CField("jcruuid", "Text");
	m_pInbound->m_colFlds[i++] = new CField("ontime", "DateTime");
	m_pInbound->m_colFlds[i++] = new CField("offtime", "DateTime");







	m_pInbound->m_base.m_fieldCount = m_pInbound->m_colFlds.size();

	m_selChg = false;
	return true;
}

BOOL CPage1::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	oldInboundName = m_name;

	if (m_pInbound->m_base.m_state == ACTIVE)
	{
		m_editName.EnableWindow(FALSE);
		m_editFreq.EnableWindow(FALSE);
		m_editTimeout.EnableWindow(FALSE);
		m_edit_url1.EnableWindow(FALSE);
		m_edit_url1.EnableWindow(FALSE);
		m_edit_url2.EnableWindow(FALSE);
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPage1::OnChangeFreq() 
{
	SetModified();	
	m_selChg = true;
}

void CPage1::OnChangeName() 
{
	SetModified();	
	m_selChg = true;
}


void CPage1::OnEnChangeUtimeout()
{
	SetModified();
	m_selChg = true;
}
