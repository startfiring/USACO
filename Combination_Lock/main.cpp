/*
ID: kang_zi1
PROG: combo
LANG: C++
*/
 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int x,y,z;
};
node key1,key2;
int N,ans;
bool flag[102][102][102];
int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    memset(flag,false,sizeof(flag));
    cin >> N;
    cin >> key1.x >> key1.y >> key1.z;
    cin >> key2.x >> key2.y >> key2.z;
 
    for(int i=key1.x+N-2;i<=key1.x+N+2;i++)
    {
        for(int j=key1.y+N-2;j<=key1.y+N+2;j++)
        {
            for(int z=key1.z+N-2;z<=key1.z+N+2;z++)
            {
                if(!flag[i%N][j%N][z%N])
                {
                    ans++;
                    flag[i%N][j%N][z%N]=true;
                }
            }
        }
    }
    for(int i=key2.x+N-2;i<=key2.x+N+2;i++)
    {
        for(int j=key2.y+N-2;j<=key2.y+N+2;j++)
        {
            for(int z=key2.z+N-2;z<=key2.z+N+2;z++)
            {
                if(!flag[i%N][j%N][z%N])
                {
                    ans++;
                    flag[i%N][j%N][z%N]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}