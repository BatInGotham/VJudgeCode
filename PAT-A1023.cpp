// PAT-A1023
#include <iostream>
#include <cstdio>
#include <cstring>

char origin[25];
int cnt_origin[10];
int result[10];

int main()
{
    scanf("%s", origin);
    for(int i = 0; i < 10; i++) {
        cnt_origin[i] = result[i] = 0;
    }
    bool add = false;
    for(int i = strlen(origin)-1; i >= 0; i--) {
        int num = origin[i] - '0';
        cnt_origin[num]++;
        if(add) {
            result[(num*2+1) % 10]++;
            origin[i] = '0' + (num*2+1) % 10;
            if(num*2+1 >= 10)
                add=true;
            else
                add=false;
        } else {
            result[num*2 % 10]++;
            origin[i] = '0' + (num*2) % 10;
            if(num*2 >= 10)
                add=true;
            else
                add=false;
        }
    }
    if(add) {
        printf("No\n");
        printf("1%s", origin);
        return 0;
    }
    for(int i = 0; i < 10; i++) {
        if(result[i] != cnt_origin[i]) {
            printf("No\n");
            printf("%s", origin);
            return 0;
        }
    }
    printf("Yes\n");
    printf("%s", origin);
    return 0;
}
