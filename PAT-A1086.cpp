// PAT-A1086
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

struct Node{
    Node* Left;
    Node* Right;
    int value;
};

int N;
Node* Root;

Node* buildTree(Node* &leaf) {
    string s;
    int num;
    if(cin >> s && s == "Push") {
        leaf = new Node;
        leaf->Left = leaf->Right = NULL;
        cin >> num;
        leaf->value = num;
        buildTree(leaf->Left);
        buildTree(leaf->Right);
    }
    return leaf;
}

void postTraversal(Node* node) {
    if(node->Left != NULL) {
        postTraversal(node->Left);
    }
    if(node->Right != NULL) {
        postTraversal(node->Right);
    }
    if(Root->value != node->value)
        cout << node->value << " ";
    else
        cout << node->value;
}

int main()
{
    cin >> N;
    Root = buildTree(Root);
    postTraversal(Root);
    return 0;
}
