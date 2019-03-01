// PAT-A1008
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

long N;
int arr[100010];
int main()
{
    int sum = 0;
    scanf("%ld", &N);
    arr[0] = 0;
    for (long i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > arr[i-1])
            sum += (arr[i] - arr[i-1]) * 6;
        else if (arr[i] < arr[i-1])
            sum += (arr[i-1] - arr[i]) * 4;
        sum += 5;
    }
    printf("%d", sum);
}
