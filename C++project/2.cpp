#include <iostream>
using namespace std;
char read[10005],write[10005];
int pos[10005];
int main()
{
    int now = 0,tot = 0;
    while(read[now] = cin.get())
    {
        if(read[now] == EOF) break;
        if((read[now] >= 'a' && read[now] <= 'z')||(read[now] >= 'A' && read[now] <= 'Z'))
        {
            int cur = read[now];
            if(read[now] >= 'A' && read[now] <= 'Z') cur = read[now] - 'A' + 'a';
            write[++tot] = cur;
            pos[tot] = now;
        }
        now++;
    }
    // for (int i = 1; i <= tot;i++)
    // cout << write[i];
    // cout << endl;
    int ans = 0,start = 0,end = 0;
    for (int i = 1;i <= tot; i++)
    {
        int len = 1 , range = 0;
        for (int j = 1;i - j  >= 1 && i + j <= tot; j++)
        {
            if(write[i - j] != write[i + j]) break;
            len+=2;
            range = j;
        }
        if(ans < len) 
        {
            start = i - range;
            end = i + range;
            ans = len;
        }
    }
    for (int i = 1;i < tot; i++)
        if(write[i] == write[i + 1])
        {
            int len = 2, range = 0;
            for(int j = 1;i - j >= 1 && i + j + 1 <= tot;j++)
            {
                if(write[i - j] != write[i + j + 1]) break;
                len+=2;
                range = j;
            }
            if(ans < len)
            {
                ans = len;
                start = i - range;
                end = i + range + 1;
            }
        }
    cout << ans << endl;
    for (int i = pos[start]; i <= pos[end];i++) cout << read[i];    
    return 0;
}