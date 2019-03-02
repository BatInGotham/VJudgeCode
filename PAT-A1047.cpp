// PAT-A1047
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
char name[40010][5];
vector<int> courses[2510];
int N, k;

bool cmp(int a, int b)
{
    return strcmp(name[a], name[b]) < 0;
}

int main()
{
    scanf("%d%d", &N, &k);
    for(int i = 0; i < N; i++) {
        int course_cnt;
        scanf("%s%d", name[i], &course_cnt);
        for(int j = 0; j < course_cnt; j++) {
            int course_id;
            scanf("%d", &course_id);
            courses[course_id].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for(int j = 0; j < courses[i].size(); j++) {
            printf("%s\n", name[courses[i][j]]);
        }
    }
    return 0;
}
