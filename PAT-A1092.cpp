// PAT-A1092

#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    char s1[1010];
    char s2[1010];
    int a[256];
    for (int i = 0; i < 256; i++)
        a[i] = 0;
    scanf("%s", s1);
    scanf("%s", s2);
    int cnt = 0;
    bool foo = true;
    for (int i = 0; i < strlen(s2); i++) {
        a[s2[i]]++;
    }
    for (int i = 0; i < strlen(s1); i++) {
        if (a[s1[i]] <= 0) {
            cnt++;
        } else {
            a[s1[i]]--;
        }
    }
    int sum = 0;
    for (int i = 0; i < 256; i++) {
        sum += a[i];
    }
    if (sum > 0) {
        printf("No %d", sum);
    } else {
        printf("Yes %d", cnt);
    }
}
