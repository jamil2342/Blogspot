#pragma  once

//#include <cstring>
//#include <atlstr.h>
//#include <fstream>
using namespace std;
//#include <stdio.h>
//#include <afxwin.h>
int method = 1;


struct basicInfo
{
	string  url;
	int refreshTime;
};

basicInfo a;
char filename[] = "disk6.dat";
void writeDisk()
{
	FILE *file = fopen(filename, "ab");
	fwrite(&a, sizeof(basicInfo), 1, file);
	fclose(file);
}
void emptyDisk()
{

	FILE *file = fopen(filename, "rw");
	fopen("disk1.dat", "wb");

}
void loadDisk()
{
	FILE *file = fopen(filename, "rb");
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