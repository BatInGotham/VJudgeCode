// PAT-A1037
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

double Cmax, D, Davg;
int N;

struct nums {
    int poscnt;
    int pos[100010];
    int negcnt;
    int neg[100010];
} numbers1, numbers2;

bool cmp(int a, int b)
{
    if (a > 0 && b > 0)
        return a > b;
    else
        return a < b;
}

int main()
{
    numbers1.poscnt = numbers1.negcnt = 0;
    numbers2.poscnt = numbers2.negcnt = 0;
    long N;
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) {
            numbers1.pos[numbers1.poscnt++] = tmp;
        } else if (tmp < 0) {
            numbers1.neg[numbers1.negcnt++] = tmp;
        }
    }
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) {
            numbers2.pos[numbers2.poscnt++] = tmp;
        } else if (tmp < 0) {
            numbers2.neg[numbers2.negcnt++] = tmp;
        }
    }
    std::sort(numbers1.pos, numbers1.pos+numbers1.poscnt, cmp);
    std::sort(numbers1.neg, numbers1.neg+numbers1.negcnt, cmp);
    std::sort(numbers2.pos, numbers2.pos+numbers2.poscnt, cmp);
    std::sort(numbers2.neg, numbers2.neg+numbers2.negcnt, cmp);
    long total = 0;
    for (int i = 0; i < numbers1.poscnt && i < numbers2.poscnt; i++) {
        total += numbers2.pos[i] * numbers1.pos[i];
    }
    for (int i = 0; i < numbers1.negcnt && i < numbers2.negcnt; i++) {
        total += numbers2.neg[i] * numbers1.neg[i];
    }
    printf("%ld", total);
}
