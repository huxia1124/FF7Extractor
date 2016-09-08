//ExtraUse.h
//Extended functions
//Require:
//Designed for MFC or non-MFC applications
//Copyright (C) 2001 XiaHuan
//---------------------------------------------------------------------

#include "direct.h"

//Similar to the function mkdir() but igron whether the boot directory is exist
//MFC version
#ifdef _MFC_VER
#if _MFC_VER>=0x0300
void XMkDir(const CString &dir)
{
	int pos=1;
	CString tmp;
	while(pos!=0)
	{
		pos=dir.Find("\\",pos);
		if(pos==-1)
		{
			tmp=dir;
		}
		else
		{
			tmp=dir.Left(pos+1);
		}
		pos++;
		mkdir(tmp);
	}
}
#endif
#endif

//Similar to the function mkdir() but igron whether the boot directory is exist
//non-MFC version
void XMkDir(char *chdir)
{
	unsigned int pos=0;
	char mdk[_MAX_PATH];
	while(*(chdir+pos)!='\0')
	{
		pos++;

		if(*(chdir+pos)=='\\'||*(chdir+pos)=='\0')
		{
			strncpy(mdk,chdir,pos);
			mdk[pos]='\\';
			mdk[pos+1]='\0';
			mkdir(mdk);
		}
	}
}
