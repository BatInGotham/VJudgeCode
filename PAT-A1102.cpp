// PAT-A1102
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N;

struct Node{
    int left;
    int right;
} nodes[11];

void level_order(int pos) {
    queue<int> q;
    q.push(pos);
    int cnt = 0;
    while(!q.empty()) {
        int top = q.front(); q.pop(); cnt++;
        if(cnt != N)
            cout << top << " ";
        else
            cout << top;
        if(nodes[top].left != -1) {
            q.push(nodes[top].left);
        }
        if(nodes[top].right != -1) {
            q.push(nodes[top].right);
        }
    }
    cout << endl;
}

bool isfirst = true;

void inorder(int pos) {
    if(nodes[pos].left != -1) {
        inorder(nodes[pos].left);
    }
    if(isfirst){
        cout << pos;
        isfirst = false;
    } else {
        cout << " " << pos;
    }
    if(nodes[pos].right != -1) {
        inorder(nodes[pos].right);
    }
}

int main()
{
    cin >> N;
    bool root[11];
    for(int i = 0; i < 11; i++)
        root[i] = false;
    for(int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1[0] == '-')
            nodes[i].right = -1;
        else {
            nodes[i].right = s1[0] - '0';
            root[s1[0] - '0'] = true;
        }
        if(s2[0] == '-')
            nodes[i].left = -1;
        else {
            nodes[i].left = s2[0] - '0';
            root[s2[0] - '0'] = true;
        }
    }
    int Rot = -1;
    for(int i = 0; i < N; i++) {
        if(root[i] == false) {
            Rot = i;
            break;
        }
    }
    level_order(Rot);
    inorder(Rot);
}
