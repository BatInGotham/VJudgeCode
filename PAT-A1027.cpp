// PAT-A1027
#include <iostream>
#include <cstdio>
#include <cstring>
int R, G, B;
char number[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

void mars(int num)
{
    printf("%c", number[num/13]);
    printf("%c", number[num%13]);
}

int main()
{
    scanf("%d%d%d", &R, &G, &B);
    printf("#");
    mars(R);
    mars(G);
    mars(B);
}
