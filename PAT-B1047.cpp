// PAT-B1047

#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int total[1010];
    for (int i = 0; i < 1010; i++)
        total[i] = 0;
    int lines;
    scanf("%d", &lines);
    for (int i = 0; i < lines; i++) {
        int tid, mid, score;
        scanf("%d", &tid);
        getchar();
        scanf("%d", &mid);
        scanf("%d", &score);
        total[tid] += score;
    }
    int max = 0;
    int max_id = 0;
    for (int i = 0; i < 1010; i++) {
        if (max < total[i]) {
            max = total[i];
            max_id = i;
        }
    }
    printf("%d %d", max_id, total[max_id]);
}
