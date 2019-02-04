#include <iostream>
#include <cstdio>
#include <cstring>

int cnt[10];

void process(int n)
{
    while(n != 0)
    {
        cnt[n % 10]++;
        n /= 10;
    }
}

int main()
{
    int testn = 0;
    std::cin >> testn;
    for(int i = 0; i < testn; i++)
    {
        for(int j = 0; j < 10; j++)
            cnt[j] = 0;
        int n;
        std::cin >> n;
        for(int j = 1; j <= n; j++)
            process(j);
        for(int j = 0; j < 9; j++)
            printf("%d ", cnt[j]);
        printf("%d\n", cnt[9]);
    }
}
