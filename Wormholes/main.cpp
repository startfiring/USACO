
/*
ID: kangzi1
TASK: wormhole
LANG: C++                 
*/

#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
#define MAXN 12
int partner[MAXN+1],x[MAXN+1],y[MAXN+1],right_next[MAXN+1];
int N;
bool judge()
{
    int pos;
    for(int start = 1;start<=N;start++){
        pos = start;
        for(int i = 0;i<N;i++){
            pos = partner[right_next[pos]];
        }
        if(pos!=0)
            return true;
    }
    return false;
}
int solve()
{
    int i,ret = 0;
    for(i = 1;i<=N;i++)
        if(!partner[i])
            break;
    if(i == N + 1)
    {
        if(judge())
            ret++;
        return ret;
    }
    for(int j = i + 1;j<=N;j++){
        if(!partner[j]){
            partner[i] = j;
            partner[j] = i;
            ret += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return ret;
}
int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin>>N;
    for(int i = 1;i<=N;i++)
        fin>>x[i]>>y[i];
    for(int i = 1;i<=N;i++)
    {
        for(int j = 1;j<=N;j++)
        {
            if(x[j] > x[i] && y[i] == y[j])
                if(right_next[i] == 0||x[j]-x[i]<x[right_next[i]]-x[i])
                    right_next[i] = j;
        }
    }

    fout<<solve()<<endl;

}