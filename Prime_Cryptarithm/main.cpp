/*
ID: kangzi1
TASK: crypt1
LANG: C++                 
*/
#include<iostream>
using namespace std;

int N;
int digits[9];

bool check(int number,int size)
{
    int temp=0;
    while(size--)
    {
        bool flag=false;
        temp=number%10;
        number/=10;
        for(int i=0;i<N;++i)
        {
            if(temp==digits[i])
                flag=true;
        }
        if(!flag)
            return false;
    }
    return true;
}

void solve()
{
    int num,num2,rec=0;
    int pro1,pro2,pro3;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k)
                for(int m=0;m<N;++m)
                    for(int n=0;n<N;++n)
                    {
                        num=digits[i]*100+digits[j]*10+digits[k];
                        num2=digits[m]*10+digits[n];
                        pro1=num*digits[n];
                        if(check(pro1,3) && pro1<1000)      //第一个部分乘积数不符合条件就直接考虑下一种情况
                        {
                            pro2=num*digits[m];
                            if(check(pro2,3) && pro2<1000)        //第二个部分乘积数不符合条件考虑下一种情况
                            {
                                pro3=pro2*10+pro1;
                                if(check(pro3,4) && pro3<10000)        //最终结果不符合条件考虑下一种情况
                                    ++rec;
                            }
                        }
                    }
    cout<<rec<<endl;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>digits[i];
    solve();
    return 0;
}