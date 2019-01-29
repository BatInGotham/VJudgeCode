#include <iostream>
#include <cstdio>

using namespace std;

int digit(int i)
{
    int a,b,c,d,e,x;
    e = i % 10;
    d = (i / 10) % 10;
    c = (i / 100) % 10;
    b = (i / 1000) % 10;
    a = (i / 10000) % 10;
    x = (i / 100000);
    return a+b+c+d+e+x;
}

int main()
{
    int a[100001][2];
    for(int i = 1; i < 100001; i++)
    {
        a[i][0] = i;
        a[i][1] = i + digit(i);
    }
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int c;
        bool find = false;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            if(a[j][1] == c) {
                cout << a[j][0] << endl;
                find = true;
                break;
            }
        }
        if(find == false)
            cout << 0 << endl;
    }
    return 0;
}
