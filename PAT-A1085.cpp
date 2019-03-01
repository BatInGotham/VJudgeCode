// PAT-A1085
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int N, p;
int a[100010];

int main()
{
    scanf("%d%d", &N, &p);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a+N);
    int ans = 1;
    for (int i = 0; i < N; i++) {
        int j = upper_bound(a+i+1, a+N, (long long)a[i]*p) - a;
        ans = max(ans, j-i);
    }

    printf("%d\n", ans);
    return 0;
}
