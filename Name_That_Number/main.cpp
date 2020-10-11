
/*
ID:kangzi1
PROG:namenum
LANG:C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<fstream>
using namespace std;
int main()
{
	FILE *fin2=fopen("dict.txt","r"); 
	FILE *fin1=fopen("namenum.in","r");
	FILE *fout=fopen("namenum.out","w");
	char list[256];
list['A']=list['B']=list['C']='2';
list['D']=list['E']=list['F']='3';
list['G']=list['H']=list['I']='4';
list['J']=list['K']=list['L']='5';
list['M']=list['N']=list['O']='6';
list['P']=list['R']=list['S']='7';
list['T']=list['U']=list['V']='8';
list['W']=list['X']=list['Y']='9';
	char num[15];
	char word[15];
	char *p,*q;
	int cal=0;
	fscanf(fin1,"%s",&num);
	int lennum=strlen(num);
	while(fscanf(fin2,"%s",&word)!=EOF)
	{
		for(p=word,q=num;*p&&*q;p++,q++)
		{
			if(list[*p]!=*q)
			break;
		}
		if(*p=='\0'&&*q=='\0')
		{
			fprintf(fout,"%s\n",word);
			cal++;
		}
	}
	if(cal==0)
	fprintf(fout,"NONE\n");
	return 0;
}