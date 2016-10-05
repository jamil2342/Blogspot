// FastMoneyAdapter.h

#pragma once
#pragma once
#include <vcclr.h>
//#include "IFastMoneyAdapter.h"
#include <list>

#pragma once 

#include "targetver.h"
#include <OAIdl.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
using namespace System;
using namespace AemClient;
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;
namespace FastMoneyAdapter {

	public ref class MyAdapter
	{
		myCleint ^ myCl;
		// TODO: Add your methods for this class here.
	};
	public class __declspec(dllexport) MyClass
	{
		gcroot<myCleint ^>	myclient;
	public:
		MyClass()
		{
			myclient = gcnew myCleint();
		}
		~MyClass()
		{
		}

		void RetrieveListItems(wchar_t* listName, VARIANT *vValues, int &ret)
		{

			//DataTable^ DT = _managedObject->RetrieveListItems(gcnew String(listName));
			DataTable ^ DT = myclient->GetFastMoneyDataTable();
			//String^ error = _managedObject->LastError;
			LONG lRow = 0;
			SAFEARRAY *psa;
			//LONG lStores = 0;
			SAFEARRAYBOUND saBoundNew;
			VARIANT vtTemp;
			VariantInit(&vtTemp);
			long ubound;
			//if ( error != nullptr )
			//{
			//	if ( error->Length > 0 )
			//	{
			//		ret = 1;
			//		return;
			//	}
			//}
			if (DT == nullptr)
			{
				return;
			}
			if (vValues->vt == (VT_ARRAY | VT_VARIANT))
			{
				psa = vValues->parray;
				SafeArrayGetUBound(psa, 1, &ubound);
				saBoundNew.lLbound = 0;
				saBoundNew.cElements = ubound + 1 + (DT->Columns->Count * (DT->Rows->Count * 2) + 1);
				SafeArrayRedim(psa, &saBoundNew);
				lRow = ubound + 1;
			}
			else
			{
				VariantInit(vValues);
				vValues->vt = VT_ARRAY | VT_VARIANT;
				psa = SafeArrayCreateVector(VT_VARIANT, 0, DT->Columns->Count * (DT->Rows->Count * 2) + 1);
			}

			long lRow0 = 0;
			int cnt = DT->Columns->Count;
			vtTemp.vt = VT_I4;
			vtTemp.lVal = cnt;
			SafeArrayPutElement(psa, &lRow0, (void *)&vtTemp);
			if (lRow == 0)
				lRow++;

			for each (DataRow^ row in DT->Rows)
			{
				for each (DataColumn^ col in DT->Columns)
				{
					Marshal::GetNativeVariantForObject(col->ColumnName, IntPtr(&vtTemp));
					SafeArrayPutElement(psa, &lRow, (void *)&vtTemp);
					lRow++;
					VariantClear(&vtTemp);

					Marshal::GetNativeVariantForObject(row[col], IntPtr(&vtTemp));
					SafeArrayPutElement(psa, &lRow, (void *)&vtTemp);
					VariantClear(&vtTemp);
					lRow++;
				}
				//Console::WriteLine();
			}
			vValues->parray = psa;

		}




	};


}
