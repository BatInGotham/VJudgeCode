// PAT-B1043

#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    char sample[7] = "PATest";
    int index = 0;
    int cnt[6];
    for (int i = 0; i < 6; i++) {
        cnt[i] = 0;
    }
    char ch;
    int total = 0;
    while((ch = getchar()) && ch != '\n')
    {
        switch (ch) {
            case 'P': cnt[0]++; total++; break;
            case 'A': cnt[1]++; total++; break;
            case 'T': cnt[2]++; total++; break;
            case 'e': cnt[3]++; total++; break;
            case 's': cnt[4]++; total++; break;
            case 't': cnt[5]++; total++; break;
            default: break;
        }
    }
    for (int i = 0; i < total;) {
        if (cnt[index % 6] > 0) {
            printf("%c", sample[index % 6]);
            i++;
            cnt[index % 6]--;
        }
        index++;
    }

}
