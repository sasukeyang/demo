#include <bits/stdc++.h>
using namespace std;
int  poll[200000], b[200000], c[200000], d[200000];
void bubble(int n)
{    
    for( int i = n; i >= 1;i-- )
    {   
        int fla = 0;
        for (int j = 1; j <= i - 1;j++ )
            if(poll[j] > poll[j+1])
            {
                poll[j] ^= poll[j+1];
                poll[j+1] ^= poll[j];
                poll[j] ^= poll[j+1];
                fla = 1; 
            }
        if(!fla) break;
    }
}
void qsort(int l, int r)
{
//    cout << l << ' '<< r << endl;
    srand(time(NULL));
    if( l >= r) return;

    int randint = rand() % (r - l + 1) + l;
    
    int nb = 1, nc = 1,nd = 1;
    for (int i = l;i <= r;i++)
    {
        if(poll[i] < poll[randint]) 
            b[nb++] = poll[i];
        else if(poll[i] == poll[randint])
            c[nc++] = poll[i];
        else
            d[nd++] = poll[i];
    }
    nb--, nc--, nd--;
    for(int i = l ;i <= l + nb - 1;i++)
        poll[i] = b[i - l + 1];
    for(int i = l + nb; i <= l + nb + nc - 1;i++)
        poll[i] = c[i - nb - l + 1];
 //   cout << nb << " " << nc << " " << nd <<endl;
    for(int i = l + nb + nc ; i <= l + nb + nc + nd - 1;i++)
        poll[i] = d[i - nb - nc - l + 1];
    qsort(l,nb + l -1);
    qsort(r - nd + 1, r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> poll[i];
    qsort(1, n);
    for (int i = n;i >= 1; i--) cout << poll[i]<<" ";
}
