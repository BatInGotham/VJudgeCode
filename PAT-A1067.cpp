// PAT-A1067
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int N;
int nums[100010];
int k = 1;

int find(int num) {
    for (int i = 0; i < N; i++) {
        if (nums[i] == num)
            return i;
    }
    return -1;
}

int Count() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (nums[i] != i && nums[i] != 0)
            res++;
    }
    return res;
}

int main()
{
    int cnt = 0;
    scanf("%d", &N);
    for (long i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    int total = Count();
    while (total > 0) {
        if (nums[0] == 0) {
            while (k < N) {
                if (nums[k] != k) {
                    std::swap(nums[0], nums[k]);
                    cnt++;
                    break;
                }
                k++;
            }
        }
        while (nums[0] != 0) {
            std::swap(nums[0], nums[nums[0]]);
            cnt++;
            total--;
        }
    }
    printf("%d", cnt);
}
