#include <iostream>
#include <cstdio>

int main()
{
    int N, index;
    int a[110];
    scanf("%d", &N);
    scanf("%d", &index);
    for (int i = 0; i < N; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < N; i++) {
        if (i != 0)
            printf(" ");
        printf("%d", a[(i-index+100*N) % N]);
    }
}
