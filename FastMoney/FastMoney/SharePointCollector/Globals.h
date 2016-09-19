#pragma  once

//#include <cstring>
//#include <atlstr.h>
//#include <fstream>
using namespace std;
//#include <stdio.h>
//#include <afxwin.h>
int method = 0;


struct basicInfo
{
	string  url;
	int refreshTime;
};

basicInfo a;
void writeDisk()
{
	FILE *file = fopen("disk.dat", "ab");
	fwrite(&a, sizeof(basicInfo), 1, file);
	fclose(file);
}

void loadDisk()
{
	FILE *file = fopen("disk.dat", "rb");
	if (file != NULL)
	{
		fread(&a, sizeof(basicInfo), 1, file);
		fclose(file);
	}


	//AfxMessageBox(a.url);
}
//void writetoFile()
//{
//	FILE * fp = fopen("c:/jamil.txt", "w");
//	fwrite(&a, sizeof(basicInfo), 1, fp);
//	fclose(fp);
//}