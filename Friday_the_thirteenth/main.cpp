/*
ID:jsntrdy1
PROG: friday
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out"); 

int days[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
                 31,29,31,30,31,30,31,31,30,31,30,31};

int week[7];
int main()
{
    int n;
    fin>>n;
    int j;
    int day=0;
    for(int i=1900;i<=1900+n-1;i++)
    {
        int isLeap=((i%4==0&&i%100!=0)||i%400==0)?1:0;
        for(int j=0;j<=11;j++)
        {
            week[(day+13)%7]++;
            day+=days[isLeap][j];   
        }   

    }
    fout<<week[6]<<' ';
    for(int i=0;i<5;i++)
      fout<<week[i]<<' ';
    fout<<week[5]<<endl;
    fin.close();
    fout.close();
    return 0;
}