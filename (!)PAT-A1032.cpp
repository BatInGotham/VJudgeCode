// PAT-A1032
#include <iostream>
#include <cstdio>

struct Node {
    int next;
    char data;
    bool flag;
} nodes[100010];

int main()
{
    for(int i = 0; i < 100010; i++)
        nodes[i].flag = false;
    int addr1, addr2, num;
    scanf("%d%d%d", &addr1, &addr2, &num);
    for(int i = 0; i < num; i++) {
        int address, next;
        char data;
        scanf("%d %c %d", &address, &data, &next);
        nodes[address].next = next;
        nodes[address].data = data;
    }
    for(int i = addr1; nodes[i].next != -1; i = nodes[i].next) {
        nodes[i].flag = true;
    }
    int j;
    for(j = addr2; nodes[j].next != -1; j = nodes[j].next) {
        if(nodes[j].flag) {
            break;
        }
    }
    if(nodes[j].next != -1) {
        printf("%05d", j);
    } else {
        printf("-1");
    }
    return 0;
}
