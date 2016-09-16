#include "StdAfx.h"
#include "IFastMoneyAdapter.h"
#include "FastMoneyAdapter.h"

ISharePointAdapter *ISharePointAdapter::CreateInstance(void)
{
	return ((ISharePointAdapter *)new CSharePointAdapter());
}

void ISharePointAdapter::Destroy(ISharePointAdapter *instance)
{
	instance->Disconnect();
	delete instance;
}
