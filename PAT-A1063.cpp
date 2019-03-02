// PAT-A1063
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
set<int> nums[51];

void compare(int s1, int s2)
{
    int totalNum = nums[s2].size(), sameNum = 0;
    for(set<int>::iterator it = nums[s1].begin(); it != nums[s1].end(); it++) {
        if(nums[s2].find(*it) != nums[s2].end())
            sameNum++;
        else
            totalNum++;
    }
    printf("%.1f%%\n", sameNum*100.0/totalNum);
    return;
}

int main()
{
    int N;

    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        int cnt;
        scanf("%d", &cnt);
        for(int j = 0; j < cnt; j++) {
            int num;
            scanf("%d", &num);
            nums[i].insert(num);
        }
    }

    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        int s1, s2;
        scanf("%d%d", &s1, &s2);
        compare(s1, s2);
    }
    return 0;
}
