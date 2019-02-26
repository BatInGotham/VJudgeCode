// PAT-A1025


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

struct Stu {
    char id[15];
    int score;
    int group_num;
    int total, group_cnt;
} stu[30010];

int group_cnt, stu_cnt;
int stu_total;
int gid[105][3]; // [][0] 名次 [][1] 上一个名次 [][2] 上一个成绩

bool cmp(Stu a, Stu b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    stu_total = 0;
    scanf("%d", &group_cnt);
    for(int i = 0; i < group_cnt; i++) {
        scanf("%d", &stu_cnt);
        for(int j = 0; j < stu_cnt; j++) {
            scanf("%s%d", stu[stu_total].id, &stu[stu_total].score);
            stu[stu_total].group_num = i+1;
            stu_total++;
        }
        gid[i][0] = 1;
        gid[i][1] = 1;
        gid[i][2] = -1;
        std::sort(stu+stu_total-stu_cnt, stu+stu_total, cmp);
        stu[stu_total - stu_cnt].group_cnt = 1;
        for (int j = stu_total - stu_cnt + 1; j < stu_total; j++) {
            if (stu[j].score == stu[j-1].score) {
                stu[j].group_cnt = stu[j-1].group_cnt;
            } else {
                stu[j].group_cnt = j + 1 - (stu_total - stu_cnt);
            }
        }
    }
    std::sort(stu, stu+stu_total, cmp);
    stu[0].total = 1;
    for (int i = 1; i < stu_total; i++) {
        if (stu[i].score == stu[i-1].score)
            stu[i].total = stu[i-1].total;
        else
            stu[i].total = i+1;
    }
    printf("%d\n", stu_total);
    for (int i = 0; i < stu_total; i++) {
        printf("%s %d %d %d\n", stu[i].id, stu[i].total, stu[i].group_num, stu[i].group_cnt);
    }
    return 0;
}
