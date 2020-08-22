/*
ID:kangzi1
LANG:C++
TASK:milk2
*/

#include<stdio.h>
#include<algorithm>
using namespace std;

bool qdu[1000001];

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n;
    int res1 = 0;
    scanf("%d",&n);
    int max_b = 0;
    int min_a = 1000001;
    while(n--)
    {
        int a;
        int b;
        scanf("%d%d",&a,&b);
        min_a = min(min_a,a);
        max_b = max(max_b,b);
        for(int i = a+1;i <= b;i++) qdu[i] = 1;
    }
    int res2 = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    for(int i = min_a;i <= max_b+1;i++)
    {
        if(qdu[i])  tmp1++;
        else
        {
            res1 = max(res1,tmp1);
            tmp1 = 0;
        }
    }
    for(int i = min_a+1;i <= max_b;i++)
    {
        if(!qdu[i]) tmp2++;
        else
        {
            res2 = max(res2,tmp2);
            tmp2 = 0;
        }
    }
    printf("%d %d\n",res1,res2);
    return 0;
}