// PAT-A1080

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int stu_num, school_num, choice_num;

struct Student {
    int id;
    int GE, GI, total;
    int rank;
    int choice[6];
} stu[40010];

struct School {
    int id;
    int cnt;
    int stu_num;
    int stu_id[40010];
    int lastRank;
} school[105];

bool cmp(Student a, Student b) {
    if (a.total != b.total)
        return a.total > b.total;
    else if (a.GE != b.GE)
        return a.GE > b.GE;
    else
        return a.id < b.id;
}

int main()
{
    scanf("%d%d%d", &stu_num, &school_num, &choice_num);
    for (int i = 0; i < school_num; i++) {
        school[i].id = i;
        scanf("%d", &school[i].cnt);
        school[i].stu_num = 0;
        school[i].lastRank = -1;
    }
    for (int i = 0; i < stu_num; i++) {
        stu[i].id = i;
        scanf("%d%d", &stu[i].GE, &stu[i].GI);
        for (int j = 0; j < choice_num; j++) {
            scanf("%d", &stu[i].choice[j]);
        }
        stu[i].total = stu[i].GE + stu[i].GI;
    }
    std::sort(stu, stu+stu_num, cmp);
    stu[0].rank = 0;
    for (int i = 1; i < stu_num; i++) {
        if (stu[i].total == stu[i-1].total && stu[i].GE == stu[i-1].GE)
            stu[i].rank = stu[i-1].rank;
        else
            stu[i].rank = i;
    }
    for (int i = 0; i < stu_num; i++) {
        for (int j = 0; j < choice_num; j++)
        {
            int tmp_school = stu[i].choice[j];
            if (school[tmp_school].cnt > 0) {
                school[tmp_school].stu_id[school[tmp_school].stu_num++] = stu[i].id;
                school[tmp_school].cnt--;
                school[tmp_school].lastRank = stu[i].rank;
                break;
            }
            else if (stu[i].rank == school[tmp_school].lastRank) {
                school[tmp_school].stu_id[school[tmp_school].stu_num++] = stu[i].id;
                break;
            }
        }
    }
    for (int i = 0; i < school_num; i++) {
        std::sort(school[i].stu_id, school[i].stu_id+school[i].stu_num);
    }
    for (int i = 0; i < school_num; i++) {
        int j;
        for (j = 0; j < school[i].stu_num-1; j++) {
            printf("%d ", school[i].stu_id[j]);
        }
        if (j == school[i].stu_num - 1)
            printf("%d", school[i].stu_id[j]);
        printf("\n");
    }
}
