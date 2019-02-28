// PAT-A1070
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

struct Mooncake {
    double price;
    double cnt;
} cake[1010];

bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int N;
    double total;
    scanf("%d%lf", &N, &total);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &cake[i].cnt);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lf", &cake[i].price);
        cake[i].price /= cake[i].cnt;
    }
    std::sort(cake, cake+N, cmp);
    double money = 0;
    int i = 0;
    while (total >= cake[i].cnt && i < N) {
        money += cake[i].cnt * cake[i].price;
        total -= cake[i].cnt;
        i++;
    }
    money += cake[i].price * total;
    printf("%.2f", money);
}
