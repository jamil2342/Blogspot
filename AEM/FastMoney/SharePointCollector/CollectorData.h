#pragma once
#include "mtobject6.h"
//#include "FastMoneyAdapter.h"
class CEventThread;
#define FASTMONEY_ERROR_RECOVERY_TIMEOUT 120

class CCollectorData :
	public MTObject
{
	wchar_t * url = L"http://podcast.cnbc.com/mmpodcast/fastmoney.xml";
public:
	CCollectorData(void);
	~CCollectorData(void);
	CEventThread* m_pThreadMgr;				// Ptr to the parent
	map<string, string> m_mapImages;

	void InitData(CEventThread *pThread);	
	void DoQuery();
	void DoQueryLocal();
	void PublishFields();
	int m_ConnectionOpen;
	bool m_bQuitProcessing;		// Flag to help others quit early
	bool m_bRandom;
	int m_nErrorRecovery;

	ULONG Connect();
	void  doDisconnect();
	int m_iDataCounter;

protected:
	
	void StopData();
	void SetErrMsg(ULONG);		// Retrieve some help!!
	char m_szErrMsg[100];
	_CrtMemState m_s1, m_s2, m_s3;
};


