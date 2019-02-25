#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/* PAT-A1062 */

int N, L, H; // total number N, low bound L, high bound H
// L >= 60 && H < 100

struct Student {
    char id[10];
    int de, cai, total;
    int lvl; // 0~4
}stu[100010];

bool cmp(Student a, Student b)
{
    if (a.lvl != b.lvl) {
       return (a.lvl > b.lvl);
    }
    else if (a.total != b.total) {
        return (a.total > b.total);
    }
    else if (a.de != b.de) {
        return (a.de > b.de);
    }
    else {
        return (strcmp(a.id, b.id) < 0);
    }
}

int main()
{
    scanf("%d%d%d", &N, &L, &H);
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        scanf("%s%d%d", stu[count].id, &stu[count].de, &stu[count].cai);
        if(stu[count].de >= L && stu[count].cai >= L) {
            stu[count].total = stu[count].de + stu[count].cai;
            if(stu[count].de >= H && stu[count].cai >= H) {
                stu[count].lvl = 4;
            }else if(stu[count].de >= H && stu[count].cai >= L) {
                stu[count].lvl = 3;
            }else if(stu[count].de < H && stu[count].cai < H && stu[count].de >= stu[count].cai) {
                stu[count].lvl = 2;
            }else {
                stu[count].lvl = 1;
            }
            count++;
        }
    }
    printf("%d\n", count);
    std::sort(stu, stu+count, cmp);
    for (int i = 0; i < count; i++) {
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }
    return 0;
}
