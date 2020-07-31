/*
ID:kang_zi1
PROG:ride
LANG:C++
*/


#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream fin(".\\Your_ride_is_here\\ride.in");
    ofstream fout(".\\Your_ride_is_here\\ride.out");
    char ch1[7];
    char ch2[7];
    int term1=1;
    int term2=1;
    fin>>ch1>>ch2;
    int i=0;
    while(ch1[i]!='\0')
    {
        int ans=ch1[i]-64;
        term1*=ans;
        ++i;
    }
    i=0;
    while(ch2[i]!='\0')
    {
        int ans=ch2[i]-64;
        term2*=ans;
        ++i;
    }
    if(term1%47==term2%47)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
}