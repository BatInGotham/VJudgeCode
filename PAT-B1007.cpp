// PAT-B1007

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

int N;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    int sqt = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqt; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int cnt = 0;
    scanf("%d", &N);
    for(int i = 3; i+2 <= N; i+=2) {
        if(isPrime(i) && isPrime(i+2))
            cnt++;
    }
    printf("%d", cnt);
}
