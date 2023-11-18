#include<bits/stdc++.h>
#define int long long 
#define re register
#define inf 1e18
const int sz=3e7+5;
using namespace std;
int p[sz];
char data[sz];
int cnt=0;
void turn()
{
	char c=getchar();
	data[0]='~';
	data[cnt=1]='|';
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') data[++cnt]=c,data[++cnt]='|',c=getchar(); 
}
int mx=0,id,ans;
signed main()
{
	turn();
	for(int i=1;i<=cnt;i++)
	{
		if(i<mx) p[i]=min(p[(id<<1)-i],mx-i);
		else p[i]=1;
		while(data[i-p[i]]==data[i+p[i]]) p[i]++;
		if(i+p[i]>mx) 
		{
			mx=i+p[i];
			id=i;
		}
		ans=max(ans,p[i]-1);
	}
	cout<<ans<<endl;
}