/*
ID: kangzi1
TASK: barn1
LANG: C++                 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int M,S,C;
int stalls[201],gap[201];

void solve()
{
    int len=stalls[C-1]-stalls[0]+1;
    for(int i=0;i<C-1;++i)
        gap[i]=stalls[i+1]-stalls[i]-1;
    sort(gap,gap+C-1);
    for(int i=C-2;i>C-M-1;--i)
        len-=gap[i];
    cout<<len<<endl;
}

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    cin>>M>>S>>C;
    for(int i=0;i<C;++i)
        cin>>stalls[i];
    sort(stalls,stalls+C);         //按照牛所占牛棚编号从小到大排序
    if(M>=C)
        cout<<C<<endl;
    else
        solve();
    return 0;
}
