// PAT-A1130
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
    string token;
} nodes[30];

bool hasson(int pos) {
    if(nodes[pos].left != -1 || nodes[pos].right != -1)
        return true;
    return false;
}

void inorder(int pos) {
    if(nodes[pos].left != -1 && hasson(nodes[pos].left)) {
        cout << "(";
        inorder(nodes[pos].left);
        cout << ")";
    } else if(nodes[pos].left != -1) {
        inorder(nodes[pos].left);
    }
    cout << nodes[pos].token;
    if(nodes[pos].right != -1 && hasson(nodes[pos].right)) {
        cout << "(";
        inorder(nodes[pos].right);
        cout << ")";
    } else if(nodes[pos].right != -1) {
        inorder(nodes[pos].right);
    }
}

int main()
{
    cin >> N;
    bool root[30];
    for(int i = 0; i < 30; i++)
        root[i] = false;
    for(int i = 1; i <= N; i++) {
        string s1;
        int i2, i3;
        cin >> s1 >> i2 >> i3;
        if(i2 == -1)
            nodes[i].left = -1;
        else {
            nodes[i].left = i2;
            root[i2] = true;
        }
        if(i3 == -1)
            nodes[i].right = -1;
        else {
            nodes[i].right = i3;
            root[i3] = true;
        }
        nodes[i].token = s1;
    }
    int Rot = 0;
    for(int i = 1; i <= N; i++) {
        if(!root[i]) {
            Rot = i;
            break;
        }
    }
    inorder(Rot);
}
