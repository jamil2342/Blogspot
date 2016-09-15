#include "stdafx.h"
#include "FastMoneyDataAdapter.h"

CFastMoneyDataAdapter::CFastMoneyDataAdapter()
{
	_managedObject = gcnew Class1();
}

void CFastMoneyDataAdapter::RetrieveListItems(wchar_t* listName, VARIANT *vValues, int &ret)
{


	DataTable^ DT = _managedObject->RetrieveListItems(gcnew String(listName));

	LONG lRow = 0;
	SAFEARRAY *psa;
	//LONG lStores = 0;
	SAFEARRAYBOUND saBoundNew;
	VARIANT vtTemp;
	VariantInit(&vtTemp);
	long ubound;

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
