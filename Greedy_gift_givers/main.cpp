/*
ID:kang_zi1
PROG:gift1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Person
{
    string name;
    int money;
} p[10];

int main()
{
        ofstream fout(".\\Greedy_gift_givers\\gift1.out");
        ifstream fin(".\\Greedy_gift_givers\\gift1.in");
	int a,m,n,money,num;
	string name;
	fin>>a;
	for(int i=0;i<a;i++)
	{
		fin>>p[i].name;
	}
	for(int j=0;j<a;j++)
	{
		fin>>name;
		fin>>money>>num;
		for(m=0;m<a;m++)
		    if(p[m].name==name)
				break;
			if(num!=0)
				p[m].money+=money%num;
		    p[m].money-=money;
		
		    for(m=0;m<num;m++)
			{
				fin>>name;
			    for(n=0;n<a;n++)
				{
					if(p[n].name==name)
					{
						p[n].money+=money/num;
                                                break;
					}


				}
			}
		
	}
	for(n=0;n<a;n++)
	{
		fout<<p[n].name<<" "<<p[n].money<<endl;
	}
	return 0;

}
