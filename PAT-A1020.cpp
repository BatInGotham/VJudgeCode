// PAT-A1020
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
int N;
int post[32];
int in[32];

struct Node{
    int value;
    Node *Left;
    Node *Right;
};

Node* create(Node* &root, int post_l, int post_r, int in_l, int in_r) {
    if(post_l > post_r)
        return NULL;
    root = new Node;
    int pos = -1;
    for(int i = in_l; i <= in_r; i++) {
        if(post[post_r] == in[i]) {
            pos = i;
            break;
        }
    }
    int numL = pos - in_l;
    root->value = post[post_r];
    root->Left = create(root->Left, post_l, post_l+numL-1, in_l, pos-1);
    root->Right = create(root->Right, post_l+numL, post_r-1, pos+1, in_r);
    return root;
}

void BFS(Node* &root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* from = q.front(); q.pop();
        if(from->Left)
            q.push(from->Left);
        if(from->Right)
            q.push(from->Right);
        printf("%d", from->value);
        if(!q.empty())
            printf(" ");
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }
    Node *root;
    root = create(root, 0, N-1, 0, N-1);
    BFS(root);
}
