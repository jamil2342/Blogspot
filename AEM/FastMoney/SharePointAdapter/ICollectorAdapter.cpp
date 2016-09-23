#include "StdAfx.h"
#include "ICollectorAdapter.h"
#include "CollectorAdapter.h"

ICollectorAdapter *ICollectorAdapter::CreateInstance(void)
{
	return ((ICollectorAdapter *)new CCollectorAdapter());
}

void ICollectorAdapter::Destroy(ICollectorAdapter *instance)
{
	instance->Disconnect();
	delete instance;
}
