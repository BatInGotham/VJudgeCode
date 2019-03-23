// PAT-A1004
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
struct Node{
    int level;
    bool active;
    bool isLeaf;
} nodes[110];
struct Line{
    int ID;
    int k;
    int a[110];
} lines[110];

bool cmp(Line a, Line b) {
    return a.ID < b.ID;
}

int main()
{
    for(int k = 0; k < 110; k++) {
        nodes[k].active = false;
        nodes[k].isLeaf = true;
        nodes[k].level = -1;
    }
    cin >> N >> M;
    if(N == 0)
        return 0;
    // M lines follow
    nodes[1].active = true;
    nodes[1].isLeaf = false;
    nodes[1].level = 1;
    for(int j = 0; j < M; j++) {
        cin >> lines[j].ID >> lines[j].k;
        for(int i = 0; i < lines[j].k; i++) {
            cin >> lines[j].a[i];
        }
    }
    sort(lines, lines+M, cmp);
    for(int j = 0; j < M; j++) {
        int ID;
        int k;
//        cin >> ID >> k;
        ID = lines[j].ID;
        k = lines[j].k;
        nodes[ID].active = true;
        nodes[ID].isLeaf = false;
        for(int i = 0; i < k; i++) {
            int temp;
            temp = lines[j].a[i];
            nodes[temp].active = true;
            nodes[temp].level = nodes[ID].level+1;
        }
    }
    int lvl_cnt = 0;
    int arr[110];
    for(int i = 0; i < 110; i++) {
        if(lvl_cnt < nodes[i].level)
            lvl_cnt = nodes[i].level;
        arr[i] = 0;
    }
    for(int i = 0; i < 110; i++) {
        if(nodes[i].isLeaf == true && nodes[i].active == true)
            arr[nodes[i].level]++;
    }
    for(int i = 1; i <= lvl_cnt; i++) {
        printf("%d", arr[i]);
        if(i != lvl_cnt)
            printf(" ");
    }
}
