// PAT-A1015
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

int N;
int D;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    int sqt = (int)sqrt(1.0*n);
    for(int i = 2; i <= sqt; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int d[100010];

int main()
{
    while(scanf("%d%d", &N, &D) != 0 && N >= 0) {
        if(!isPrime(N)) {
            printf(("No\n"));
            continue;
        } else {
            int len = 0;
            do {
                d[len++] = N % D;
                N /= D;
            } while(N != 0);
            for(int i = 0; i < len; i++) {
                N = N * D + d[i];
            }
            if(isPrime(N)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
