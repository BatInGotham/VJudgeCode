#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool comp(int c1[26], int c2[26])
{
    for(int i = 0; i < 26; i++)
    {
        if(c1[i] != c2[i])
            return false;
    }
    return true;
}

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    char s1[105], s2[105];
    while(scanf("%s", s1) == 1)
    {
        scanf("%s", s2);
        int c1[26], c2[26];
        for(int i = 0; i < 26; i++)
        {
            c1[i] = c2[i] = 0;
        }
        int len = strlen(s1);
        for(int i = 0; i < len; i++)
        {
            c1[s1[i]-'A']++;
            c2[s2[i]-'A']++;
        }
        sort(c1, c1+26, cmp);
        sort(c2, c2+26, cmp);
        if(comp(c1,c2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
