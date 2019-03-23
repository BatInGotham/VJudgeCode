// PAT-A1006
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Record {
    string ID;
    int in_h, in_m, in_s;
    int out_h, out_m, out_s;
} records[110];

bool cmp1(Record a, Record b)
{
    if(a.in_h != b.in_h)
        return a.in_h < b.in_h;
    else if(a.in_m != b.in_m)
        return a.in_m < b.in_m;
    else
        return a.in_s < b.in_s;
}

bool cmp2(Record a, Record b)
{
    if(a.out_h != b.out_h)
        return a.out_h > b.out_h;
    else if(a.out_m != b.out_m)
        return a.out_m > b.out_m;
    else
        return a.out_s > b.out_s;
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> records[i].ID;
        scanf("%d:%d:%d", &records[i].in_h, &records[i].in_m, &records[i].in_s);
        scanf("%d:%d:%d", &records[i].out_h, &records[i].out_m, &records[i].out_s);
    }
    sort(records, records+N, cmp1);
    cout << records[0].ID << " ";
    sort(records, records+N, cmp2);
    cout << records[0].ID;
}
