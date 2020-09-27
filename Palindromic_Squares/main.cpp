/*
ID: kangzi1
LANG: C++
TASK: palsquare
*/
#include <stdio.h>
 
//20以内进制各位的表示方法
char bit[20]= {'0','1','2','3','4','5','6',
               '7','8','9','A','B','C',
               'D','E','F','G','H','I','J'
              };
//进制转换函数
void trans(int b,int a)
{
    char num[20],num1[20];
    int i=0,q=0,m=a*a,n=a;
    //a的进制转换
    while(0!=n)
    {
        num1[q]=bit[n%b];
        n/=b;
        q++;
    }
    //a平方的进制转换
    while(0!=m)
    {
        num[i]=bit[m%b];
        m/=b;
        i++;
    }
    int j=0;
    while(j<=i)
    {
        if(num[j]!=num[i-j-1])
            break;
        if(j==i-1)
        {
            for(int k=q-1;k>=0; k--)
            {
                printf("%c",num1[k]);
            }
            printf(" ");
            for(int k=0; k<i; k++)
            {
                printf("%c",num[k]);
            }
            printf("\n");
        }
 
        j++;
    }
}
int main()
{
 
    int b,a;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    scanf("%d",&b);
    for(a=1; a<=300; ++a)
        trans(b,a);
    //cout <<  << endl;
    return 0;
}
