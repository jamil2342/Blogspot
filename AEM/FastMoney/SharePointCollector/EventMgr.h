// EventMgr.h: interface for the CEventMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVENTMGR_H__7A05FED3_767D_11D3_80EE_00105AA9BDD5__INCLUDED_)
#define AFX_EVENTMGR_H__7A05FED3_767D_11D3_80EE_00105AA9BDD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFastMoneyCollect;

#include "aSyncro.h"
#include <deque>

class CEventMgr;

#include "FastMoneyCommon.h"

#include "mtobject6.h"

#include "MultiThread6.h"
#include "FastMoneyData.h"
//#include "FastMoneyData.h"

enum 
{
	T_StartData,
	T_StopData,
	T_PublishFields,
	T_GetImplementedForIB
};

class CDBEvent 
{
public:
	CDBEvent::CDBEvent(int which = 0)
	{
		type		= which;
	}
	inline CDBEvent& operator = (const CDBEvent& src)
		{

		type		= src.type;
		return *this;
		}

	short type;		// 0 is data, 1 is open connection
};

class CEventThread : public CMultiThread
{
public:
	CEventThread(CEventMgr * parent);
	virtual ~CEventThread();

	virtual void DoWork();
	void ProcessTransaction();

	CDBEvent m_currentEvent;
	CEventMgr *pmgr;
	
	CFastMoneyData m_fastmoney;
	//CFastMoneyData m_fastmoneyData;
	void GetImplementedForIB();
	
	void StopData();

protected:
	void StartData();
	void PublishFields();
};

class CEventMgr :  MTObject
{
	friend class CDataThread;
public:
	CEventMgr();
	virtual ~CEventMgr();

	void Init(CFastMoneyCollect *pOwner);
	short m_inactive_cnt;

	CFastMoneyCollect *m_pOwner;

	CEventThread * m_pEventThread;

	void	StartData(CFastMoneyCollect *pOwner);
	void	StopData();

	BOOL SetTimerRelative(HANDLE timer, unsigned long ms);
	bool	GetNextEvent( CDBEvent& event );
	HRESULT  AddEvent(int type);

protected:
	bool m_StopPending;

	bool m_onlyOnNoActivity;
	CaSynchro m_synchPulse;

	std::deque<CDBEvent*> m_EventList;
};

#endif // !defined(AFX_EVENTMGR_H__7A05FED3_767D_11D3_80EE_00105AA9BDD3__INCLUDED_)