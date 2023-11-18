#include<iostream>
#include<algorithm>
using namespace std;

//你的代码
int swim (int p[], int n)
{
    if(n == 3) return p[0] + p[1] + p[2];
    else if(n == 2) return p[1]; 
    int t1 = (p[1] << 1) + p[0] + p[n-1];
    int t2 = (p[0] << 1) + p[n-1] + p[n-2];
    // cout << t1 << " " << t2 << endl;
    // cout << endl;
    if( t1 > t2 ) return t2 + swim(p, n - 2);
    else return t1 + swim(p, n - 2);
}
int main()
{
   	int n,p[1000],i;
    cin>>n;
    for(i=0;i<n;i++) cin>>p[i];
    sort(p,p+n);
    cout<<swim(p,n);
    return 0;
}
