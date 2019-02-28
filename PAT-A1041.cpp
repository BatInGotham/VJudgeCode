// PAT-A1041

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

struct Bet {
    int id;
    int cnt;
    int num;
} bet[10010];

bool cmp (Bet a, Bet b)
{
    return a.id < b.id;
}

int main()
{
    for (int i = 0; i < 10010; i++) {
        bet[i].id = 10011;
        bet[i].cnt = 0;
        bet[i].num = i;
    }
    int N;
    scanf("%d", &N);
    int id = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (bet[num].id == 10011) {
            bet[num].id = id++;
        }
        bet[num].cnt++;
    }
    std::sort(bet, bet+10010, cmp);
    bool foo = false;
    for (int i = 0; i < N; i++) {
        if (bet[i].cnt > 1)
            continue;
        else if (bet[i].cnt == 0)
            break;
        else {
            printf("%d", bet[i].num);
            foo = true;
            break;
        }
    }
    if (!foo) {
        printf("None");
    }
}
