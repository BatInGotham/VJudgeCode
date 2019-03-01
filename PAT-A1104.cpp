// PAT-A1104
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

long N;
double arr[100010];
int main()
{
    double sum = 0;
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
        sum += (i+1)*(N-i)*arr[i];
    }
    printf("%.2f", sum);
}
