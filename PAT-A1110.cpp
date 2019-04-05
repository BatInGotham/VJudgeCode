// PAT-A1110
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
} nodes[30];

void level_order(int pos) {
    queue<int> q;
    q.push(pos);
    int cnt = 0;
    while(!q.empty()) {
        int top = q.front(); q.pop(); cnt++;
        if(cnt == N)
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

bool isComplete(int pos) {
    queue<int> q;
    q.push(pos);
    bool complete = true;
    while(!q.empty()) {
        int top = q.front(); q.pop();
        if(nodes[top].left == -1 && nodes[top].right != -1) // left NULL right VALUE
            return false;
        if((nodes[top].left == -1 || nodes[top].right == -1) && complete) { // left or right NULL && complete is true
            complete = false;
        } else if((nodes[top].left != -1 || nodes[top].right != -1) && !complete) {
            return false;
        }
        if(nodes[top].left != -1)
            q.push(nodes[top].left);
        if(nodes[top].right != -1)
            q.push(nodes[top].right);
    }
    return true;
}

int main()
{
    cin >> N;
    bool root[30];
    for(int i = 0; i < 30; i++)
        root[i] = false;
    for(int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1[0] == '-')
            nodes[i].left = -1;
        else {
            nodes[i].left = stoi(s1);
            root[stoi(s1)] = true;
        }
        if(s2[0] == '-')
            nodes[i].right = -1;
        else {
            nodes[i].right = stoi(s2);
            root[stoi(s2)] = true;
        }
    }
    int Rot = -1;
    for(int i = 0; i < N; i++) {
        if(!root[i]) {
            Rot = i;
            break;
        }
    }
    if(isComplete(Rot)) {
        cout << "YES" << " ";
        level_order(Rot);
    } else {
        cout << "NO" << " " << Rot;
    }
}
