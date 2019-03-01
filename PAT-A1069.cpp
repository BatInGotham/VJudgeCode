// PAT-A1069
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

void itoa(int* s, int num) {
    for (int i = 3; i >= 0; i--) {
        s[i] = num % 10;
        num /= 10;
    }
}

int atoi(int *arr) {
    return arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
}

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int N;
    scanf("%d", &N);
    int t[4];
    itoa(t, N);
    std::sort(t, t+4, cmp);
    N = atoi(t);
    while (N != 0 && N != 6174) {
        int a[4];
        itoa(a, N);
        std::sort(a, a+4, cmp);
        int b[4];
        itoa(b, N);
        std::sort(b,b+4);
        int res = atoi(a) - atoi(b);
        int c[4];
        itoa(c, res);
        printf("%04d - %04d = %04d\n", atoi(a), atoi(b), res);
        N = res;
    }
}
