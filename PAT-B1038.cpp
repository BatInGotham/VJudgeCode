// PAT-B1038

#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int score[101];
    for (int i = 0; i < 101; i++) {
        score[i] = 0;
    }
    long N;
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        score[num]++;
    }
    scanf("%ld", &N);
    for(long i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (i == N-1)
            printf("%d", score[num]);
        else
            printf("%d ", score[num]);
    }
}
