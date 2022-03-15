
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<climits>
#define MAXN 100000
#define LL long long
using namespace std;
LL extended_gcd(LL a,LL b,LL &x,LL &y) //返回值为gcd(a,b)
{
    LL ret,tmp;
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    ret=extended_gcd(b,a%b,x,y);
    tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ret;
}
int main()
{
    LL N;
    while (cin>>N)
    {
        long long a1,m1;
        long long a2,m2;
        cin>>a1>>m1;
        if (N==1)
            printf("%lld\n",m1);
        else
        {
            bool flag=0;
            for (int i=2;i<=N;i++)
            {
                cin>>a2>>m2;
                if (flag==1) continue;
                long long x,y;
                LL ret=extended_gcd(a1,a2,x,y);
                if ((m2-m1)%ret!=0)
                    flag=1;
                else
                {
                    long long ans1=(m2-m1)/ret*x;
                    ans1=ans1%(a2/ret);
                    if (ans1<0) ans1+=(a2/ret);
                    m1=ans1*a1+m1;
                    a1=a1*a2/ret;
                }
            }
            if (!flag)
                cout<<m1<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}