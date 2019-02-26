// PAT-A1075

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int stu_num, q_num, sub_num;
int full_mark[6];

struct Student {
    int id;
    int score[6];
    int total_mark;
    bool show;
    int perfect;
    int rank;
} stu[10010];

bool cmp (Student a, Student b) {
    if (a.total_mark != b.total_mark)
        return a.total_mark > b.total_mark;
    else if (a.perfect != b.perfect)
        return a.perfect > b.perfect;
    else
        return a.id < b.id;
}

int main ()
{
    scanf("%d%d%d", &stu_num, &q_num, &sub_num);
    for (int i = 1; i <= stu_num; i++)
    {
        stu[i].id = i;
        stu[i].score[1] = stu[i].score[2] = stu[i].score[3] = stu[i].score[4] = stu[i].score[5] = -1;
        stu[i].total_mark = 0;
        stu[i].show = false;
        stu[i].perfect = 0;
    }
    for (int i = 1; i <= q_num; i++) {
        scanf("%d", &full_mark[i]);
    }
    for (int i = 0; i < sub_num; i++) {
        int sid, qid, score;
        scanf("%d%d%d", &sid, &qid, &score);
        if (score >= stu[sid].score[qid]) {
            if (score == -1)
                stu[sid].score[qid] = 0;
            else if (score == 0) {
                stu[sid].score[qid] = 0;
                stu[sid].show = true;
            }
            else {
                stu[sid].score[qid] = score;
                stu[sid].show = true;
            }
        }
    }
    for (int i = 1; i <= stu_num; i++) {
        for (int j = 1; j <= q_num; j++) {
            if (stu[i].score[j] == full_mark[j])
                stu[i].perfect++;
            if (stu[i].score[j] != -1)
                stu[i].total_mark += stu[i].score[j];
        }
    }
    std::sort(stu+1, stu+stu_num+1, cmp);
    stu[1].rank = 1;
    for (int i = 2; i <= stu_num && stu[i].show; i++) {
        if (stu[i].total_mark == stu[i-1].total_mark)
            stu[i].rank = stu[i-1].rank;
        else
            stu[i].rank = i;
    }
    for (int i = 1; i <= stu_num && stu[i].show; i++) {
        printf("%d %05d %d",stu[i].rank, stu[i].id, stu[i].total_mark);
        for (int j = 1; j <= q_num; j++) {
            if (stu[i].score[j] >= 0)
                printf(" %d", stu[i].score[j]);
            else
                printf(" -");
        }
        printf("\n");
    }
}
