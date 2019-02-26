#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int price[24];

struct Call {
    char id[10];
    int month, date, hour, minute;
    int state; // 1 = online, 0 = offline
} record[1010];

struct Price {
    char id[10];
    int month;
    int sum;
};

bool cmp(Call a, Call b)
{
    if (strcmp(a.id, b.id) != 0)
        return strcmp(a.id, b.id) < 0;
    else if (a.month != b.month)
        return a.month < b.month;
    else if (a.date != b.date)
        return a.date < b.date;
    else if (a.hour != b.hour)
        return a.hour < b.hour;
    else
        return a.minute < b.minute;
}

int main()
{
    for (int i = 0; i < 24; i++) {
        scanf("%d", &price[i]);
    }
    int record_cnt;
    scanf("%d", &record_cnt);
    for (int i = 0; i < record_cnt; i++) {
        scanf("%s", record[i].id);
        scanf("%d:%d:%d:%d", &record[i].month, &record[i].date, &record[i].hour, &record[i].minute);
        char tmp[10];
        scanf("%s", tmp);
        if (tmp[1] == 'f')
            record[i].state = 0;
        else
            record[i].state = 1;
    }
    sort(record, record+record_cnt, cmp);
//    for (int i = 0; i < record_cnt; i++) {
//        printf("%s %2d:%2d:%2d:%2d %s\n", record[i].id, record[i].month, record[i].date, record[i].hour, record[i].minute, record[i].state?"on-line":"off-line");
//    }
    char lastname[10] = "\0";
    for (int i = 0; i < record_cnt; i++) {
        if(strcmp(lastname, record[i].id) != 0)
        {

        }
    }
}
