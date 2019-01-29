#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int les(const char *s, int p, int q)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[(p+i)%n] != s[(q+i)%n])
            return s[(p+i)%n] < s[(q+i)%n];
    }
    return 0;
}

int main()
{
    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i++)
    {
        char s[105];
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for(int j = 1; j < n; j++)
        {
            if(les(s,j,ans)) ans = j;
        }
        for(int j = 0; j < n; j++)
            putchar(s[(j+ans) % n]);
        printf("\n");
    }
    return 0;
}
