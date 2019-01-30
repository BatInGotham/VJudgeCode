#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define maxn 25

int n, k, m, a[maxn];

int go(int p, int d, int t);

int main()
{
    while(scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        for(int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        int Left = n;
        int p1 = n, p2 = 1;
        while(Left)
        {
            p1 = go(p1, 1, k);
            p2 = go(p1, -1, m);
            printf("%3d", p1);
            Left--;
            if(p1 != p2)
            {
                printf("%3d", p2);
                Left--;
            }
            a[p1] = a[p2] = 0;
            if(Left)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}

int go(int p, int d, int t)
{
    while(t--)
    {
        do{
            p = (p+d+n-1) % n + 1;
        }while(a[p] == 0);
    }
    return p;
}
