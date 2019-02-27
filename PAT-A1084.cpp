// PAT-A1084

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

char s1[90];
char s2[90];

int main()
{
    scanf("%s%s", s1, s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    bool hashTable[128] = {false};
    for (int i = 0; i < len1; i++) {
        int j;
        char c1, c2;
        for (j = 0; j < len2; j++) {
            c1 = s1[i];
            c2 = s2[j];
            if (c1 >= 'a' && c1 <= 'z') c1 -= 32;
            if (c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if (c1 == c2)
                break;
        }
        if (j == len2 && !hashTable[c1]) {
            printf("%c", c1);
            hashTable[c1] = true;
        }
    }
    return 0;
}
