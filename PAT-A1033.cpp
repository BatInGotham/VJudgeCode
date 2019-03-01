// PAT-A1033
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

double Cmax, D, Davg;
int N;

struct Station {
    double Pi;
    double Di;
} station[510];

bool cmp(Station a, Station b) {
    return a.Di < b.Di;
}

int main()
{
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
    for (int i = 0; i < N; i++) {
        scanf("%lf%lf", &station[i].Pi, &station[i].Di);
    }
    bool reach = false;
    double run = 0;
    station[N].Di = D;
    station[N].Pi = 0;

    std::sort(station, station+N, cmp);
    if (station[0].Di != 0) {
        printf("The maximum travel distance = 0.00\n");
    } else {
        int now = 0;
        double ans = 0, nowTank = 0, MAX = Cmax * Davg;
        while (now < N) {
            int k = -1;
            double priceMin = 10000000;
            for (int i = now + 1; i <= N && station[i].Di-station[now].Di <= MAX; i++) {
                priceMin = station[i].Pi;
                k = i;
                if (priceMin < station[now].Pi) {
                    break;
                }
            }
            if (k == -1) {
                break;
            }
            double need = (station[k].Di - station[now].Di)/Davg;
            if (priceMin < station[now].Pi) {
                if (nowTank < need) {
                    ans += (need - nowTank) * station[now].Pi;
                    nowTank = 0;
                } else {
                    nowTank -= need;
                }
            } else {
                ans += (Cmax - nowTank) * station[now].Pi;
                nowTank = Cmax - need;
            }
            now = k;
        }
        if (now == N) {
            printf("%.2f", ans);
        } else {
            printf("The maximum travel distance = %.2f\n", station[now].Di + MAX);
        }
    }
    return 0;
}
