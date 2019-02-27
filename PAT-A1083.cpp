// PAT-A1083

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 100010

// global variables
int N;
int grade1, grade2;
// struct
struct Student {
    char name[12];
    char id[12];
    int score;
} stu[maxn];

bool cmp(Student a, Student b) {
    return a.score > b.score;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].score);
    }
    std::sort(stu, stu+N, cmp);
    scanf("%d%d", &grade1, &grade2);
    bool has = false;
    for (int i = 0; i < N && stu[i].score >= grade1; i++) {
        if (stu[i].score > grade2)
            continue;
        printf("%s %s\n", stu[i].name, stu[i].id);
        has = true;
    }
    if (!has)
        printf("NONE");
    return 0;
}
