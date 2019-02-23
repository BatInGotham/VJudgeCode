#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

struct Student {
    char id[8];
//    int A, C, M, E;
    int score[4];
//    int A_lvl, C_lvl, M_lvl, E_lvl;
    int lvl[4];
}stu[2010];

int data_cnt, query_cnt;

int main()
{
    cin >> data_cnt >> query_cnt;
    for(int i = 0; i < data_cnt; i++)
    {
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
        stu[i].lvl[0] = stu[i].lvl[1] = stu[i].lvl[2] = stu[i].lvl[3] = 0;
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < data_cnt; j++)
        {
            int max = 0, maxn = -1;
            for(int k = 0; k < data_cnt; k++)
            {
                if(stu[k].lvl[i] == 0 && stu[k].score[i] > max) {
                    max = stu[k].score[i];
                    maxn = k;
                }
            }
            stu[maxn].lvl[i] = j+1;
        }
    }
    // process query
    for(int i = 0; i < query_cnt; i++)
    {
        char qid[8];
        cin >> qid;
        bool found = false;
        int j;
        for(j = 0; j < data_cnt; j++)
        {
            if(!strcmp(qid,stu[j].id))
            {
                found = true;
                break;
            }
        }
        if(!found)
            printf("N/A\n");
        else
        {
            int m = data_cnt;
            int best = -1;
            for(int k = 0; k < 4; k++)
            {
                if(stu[j].lvl[k] < m) {
                    best = k;
                    m = stu[j].lvl[k];
                }
            }
            printf("%d ", m);
            switch(best) {
                case 0: printf("A\n"); break;
                case 1: printf("C\n"); break;
                case 2: printf("M\n"); break;
                case 3: printf("E\n"); break;
            }
        }
    }
    return 0;
}
