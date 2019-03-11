// PAT-A1128
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
int map[1010][1010];
int arr[1010];
int main()
{
    int K, N;
    scanf("%d", &K);
    for(int i = 1; i <= K; i++) {
        memset(map, 0, sizeof(map));
        bool ret = true;
        scanf("%d", &N);
        for(int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
        }
        for(int a = 0; a < N; a++) {
            int r = arr[a];
            int c = a+1;
            if(map[r][c]) {
                ret = false;
                break;
            }
            for(int k = 1; k+c <= N; k++) {
                map[r][c+k] = 1;
                if(r+k >= 1 && r+k <= N) {
                    map[r+k][c+k] = 1;
                }
                if(r-k >= 1 && r-k <= N) {
                    map[r-k][c+k] = 1;
                }
            }
        }
        if(ret) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
