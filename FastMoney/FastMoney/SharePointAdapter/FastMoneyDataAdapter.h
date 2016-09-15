#pragma once
#include <vcclr.h>
//#include "ISharePointAdapter.h"
#include <list>
#include <OAIdl.h>
#ifdef MANAGEDWRAPPER_EXPORTS
#define DLLAPI  __declspec(dllexport)
#else
#define DLLAPI  __declspec(dllimport)
#pragma comment (lib, "SharePointAdapter.lib") // if importing, link also
#endif

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;
//using namespace SharePointClient;
using namespace FastMoneyClient;

public class DLLAPI  CFastMoneyDataAdapter
{
	gcroot<Class1 ^>	_managedObject;
public:

	CFastMoneyDataAdapter();

	void RetrieveListItems(wchar_t* listName, VARIANT *vValues, int &ret);

};

