// PAT-A1099
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define EOF -909

struct Node{
    int Left;
    int Right;
    int value;
} nodes[110];

int N;

int index = 0;
int seq[110];
int nums[110];

void insert(int pos) {
    int num = nums[seq[pos]];
    nodes[pos].value = num;
}

void inorder(int n) {
    if(nodes[n].Left != -1) {
        inorder(nodes[n].Left);
    }
    seq[n] = index++;
    if(nodes[n].Right != -1) {
        inorder(nodes[n].Right);
    }
}

void print(int pos)
{
    queue<int> q;
    q.push(pos);
    int t;
    bool isfirst = true;
    while(!q.empty()) {
        t = q.front(); q.pop();
        if(isfirst) {
            cout << nodes[t].value;
            isfirst = false;
        } else {
            cout << " " << nodes[t].value;
        }
        if(nodes[t].Left != -1) {
            q.push(nodes[t].Left);
        }
        if(nodes[t].Right != -1) {
            q.push(nodes[t].Right);
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> nodes[i].Left >> nodes[i].Right;
        nodes[i].value = EOF;
    }
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+N);
    inorder(0);
    for(int i = 0; i < N; i++) {
        insert(i);
    }
    print(0);
    return 0;
}
