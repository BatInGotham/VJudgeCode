// PAT-A1028

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

struct Student {
    char id[10];
    char name[10];
    int score;
} stu[100010];

bool cmp1(Student a, Student b)
{
    return strcmp(a.id, b.id) < 0;
}

bool cmp2(Student a, Student b)
{
    if(strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    else
        return cmp1(a, b);
}

bool cmp3(Student a, Student b)
{
    if(a.score != b.score)
        return a.score < b.score;
    else
        return cmp1(a, b);
}

int main()
{
    int stu_num, judge;
    scanf("%d%d", &stu_num, &judge);
    for(int i = 0; i < stu_num; i++)
        scanf("%s%s%d", stu[i].id, stu[i].name, &stu[i].score);
    switch(judge) {
        case 1: std::sort(stu, stu+stu_num, cmp1); break;
        case 2: std::sort(stu, stu+stu_num, cmp2); break;
        case 3: std::sort(stu, stu+stu_num, cmp3); break;
    }
    for(int i = 0; i < stu_num; i++)
    {
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
}
