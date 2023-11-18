#include<bits/stdc++.h>
using namespace std;
bool isprime[200000];
int main()
{
    int m, n,ans = 0;
    cin >> m >> n;
    for(int i = m;i <= n;i++)
        isprime[i]=0;
    isprime[1]=1;
    for(int i = 2;i <= n;i++)
        if(!isprime[i])
            for(int j = i*i;j <= n;j+=i)
                isprime[j]=1;
    for(int i = m;i <= n;i++)
        if(!isprime[i])
            ans++;
    cout << ans;            
}