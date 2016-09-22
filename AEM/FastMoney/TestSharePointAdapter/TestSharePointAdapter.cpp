// TestSharePointAdapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ISharePointAdapter.h"
#include <iostream>
#include <fstream>

std::string get_file_contents(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
}

int _tmain(int argc, _TCHAR* argv[])
{
	VARIANT vtLists;
	VARIANT vtFields;
	VARIANT vtListItems;
	VARIANT vtNoHtml;
	VARIANT vtError;
	int ret = 0;
	VariantInit(&vtLists);
	VariantInit(&vtFields);
	VariantInit(&vtListItems);
	VariantInit(&vtNoHtml);
	VariantInit(&vtError);
	
	
	//std::string html = get_file_contents("E:\\dev\\symon\\Ladybug\\Symon Enterprise Server\\Portal\\Collectors\\SharePoint\\TestSharePointAdapter\\Corporate News - All Items.htm");
	//std::wstring widestr = std::wstring(html.begin(), html.end());
	ISharePointAdapter *spa = ISharePointAdapter::CreateInstance();
	
	spa->SetConfig(L"https://eteams.eastman.com/sites/ts744", NULL, L"xsp4564", L"Summer#1", L"NTLM", NULL, ClientAuthenticationMode::Default,  false, 60, 120);
	//spa->SetCertFile(L"C:\\Users\\teto.SYMON\\Documents\\symon.cer");
	spa->SetFuagConfig(L"Extranet Partners", NULL);
	spa->SetContentLocation(L"C:\\Program Files (x86)\\Symon Enterprise Software\\bin\\SharePointFiles");
	spa->RetrieveLists(&vtLists, ret);
	if ( ret )
		spa->GetLastError(&vtError);
	spa->SetViewTitle(L"All Items");
	//spa->RetrieveViews(L"Corporate News", &vtLists, ret);
	//if ( ret )
	//	spa->GetLastError(&vtError);
	////spa->RetrieveFields(L"Corporate News", &vtFields, ret);
	while ( vtListItems.vt == VT_EMPTY)
	{
		spa->RetrieveListItems(L"Corporate News", &vtListItems, ret);
		if ( ret )
		{
			spa->GetLastError(&vtError);
			break;
		}
		Sleep(1000);
	}
	VariantClear(&vtListItems);
	//while ( vtListItems.vt == VT_EMPTY)
	//{
	//	spa->RetrieveListItems(L"Corporate News", &vtListItems);
	//	Sleep(1000);
	//}
	spa->Disconnect();
	ISharePointAdapter::Destroy(spa);
	return 0;
}

