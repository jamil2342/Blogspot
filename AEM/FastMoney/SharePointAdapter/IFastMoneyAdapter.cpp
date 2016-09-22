#include "StdAfx.h"
#include "IFastMoneyAdapter.h"
#include "FastMoneyAdapter.h"

IFastMoneyAdapter *IFastMoneyAdapter::CreateInstance(void)
{
	return ((IFastMoneyAdapter *)new CFastMoneyAdapter());
}

void IFastMoneyAdapter::Destroy(IFastMoneyAdapter *instance)
{
	instance->Disconnect();
	delete instance;
}
