// PAT-B1023

#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int num[10]; // 0 ~ 9 cnt
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 1; i < 10; i++) {
        if (num[i] > 0) {
            printf("%d", i);
            num[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        while (num[i] > 0) {
            printf("%d", i);
            num[i]--;
        }
    }
    return 0;
}
