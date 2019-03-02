// PAT-B1013

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

int M, N;

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

int prime[1000001];
bool p[1000001] = {0};
int num = 0;

void find_prime(int n)
{
    for(int i = 2; i < 1000001; i++) {
        if(p[i] == false) {
            prime[num++] = i;
            if (num >= n)
                break;
            for(int j = i+i; j < 1000001; j+=i) {
                p[j] = true;
            }
        }
    }
}

int main()
{
    int count = 0;
    scanf("%d%d", &M, &N);
    find_prime(N);
    for(int i = M; i <= N; i++) {
        printf("%d", prime[i-1]);
        count++;
        if(count % 10 != 0 && i < N)
            printf(" ");
        else
            printf("\n");
    }
}
