// PAT-A1039
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, k;
const int MAX = 26*26*26*10 + 1;
vector<int> selectCourse[MAX];

int getID(char name[])
{
    int ret = 0;
    for(int i = 0; i < 3; i++) {
        ret = ret * 26 + (name[i] - 'A');
    }
    ret = ret * 10 + name[3] - '0';
    return ret;
}

int main()
{
    scanf("%d%d", &N, &k);
    char name[5];
    for(int i = 0; i < k; i++) {
        int course, x;
        scanf("%d%d", &course, &x);
        for(int j = 0; j < x; j++) {
            scanf("%s", name);
            int id = getID(name);
            selectCourse[id].push_back(course);
        }
    }
    for(int i = 0; i < N; i++) {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d", name, selectCourse[id].size());
        for(int j = 0; j < selectCourse[id].size(); j++) {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}
