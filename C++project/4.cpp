#include <iostream>
using namespace std;
int a[10][10],ans = 2e9;
void change(int hang, int lie)
{
    a[hang][lie] ^= 1;
    a[hang + 1][lie] ^= 1;
    a[hang -1][lie] ^= 1;
    a[hang][lie + 1] ^= 1;
    a[hang][lie - 1] ^= 1;
}
bool check()
{
    for (int i = 1; i <= 5;i++)
        for (int j = 1; j <= 5;j++)
            if(!a[i][j]) return false;
    return true;
}
void getanswer(int hang, int lie, int times)
{
    if(hang == 6)
    {    
        if(check()) 
            ans = min(ans,times);
        return;
    }
    if(hang == 1) {
        if(lie == 5) getanswer(2,1,times);
        else getanswer(hang,lie+1,times);
        change(hang,lie);
        if(lie == 5) getanswer(2,1,times + 1);
        else getanswer(hang,lie+1,times + 1);
        change(hang,lie);
    }
    else{
        if(!a[hang - 1][lie]) {
            change(hang,lie);
            if(lie == 5) getanswer(hang + 1,1,times + 1);
            else    getanswer(hang,lie + 1,times + 1);
            change(hang,lie);
        }
        else {
            if(lie == 5) getanswer(hang + 1,1,times);
            else    getanswer(hang,lie + 1,times);
        }
    }
}
int main()
{
    // int r;
    // for (int i = 1; i <= 5;i++)
    // {
    //     cin >> r;
    //     a[i][1] = r/10000;
    //     a[i][2] = (r % 10000) / 1000;
    //     a[i][3] = (r % 1000) / 100;
    //     a[i][4] = (r % 100) / 10;
    //     a[i][5] = (r % 10);
    // }
    
    // for (int i = 1;i <= 5;i++)
    // {
    //     char ch[100];
    //     cin >> ch;
    //     for (int j = 1; j <= 5; j++)
    //         a[i][j] = ch[j] - '0';  
    // }
    getanswer(1,1,0);
    if(ans != 2e9) 
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}