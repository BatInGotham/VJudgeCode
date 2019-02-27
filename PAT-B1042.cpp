// PAT-B1042

#include <iostream>
#include <cstdio>
#include <cstring>

int a[256];

int main()
{
    for (int i = 0; i < 256; i++)
        a[i] = 0;
    int max_cnt = 0;
    int max_index = 0;
    char s[1010];
    std::cin.getline(s, 1010);
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] <= 'z' && s[i] >= 'a'))
            a[s[i]]++;
        else if ((s[i] <= 'Z' && s[i] >= 'A')) {
            a[s[i] - 'A' + 'a']++;
            s[i] = s[i] - 'A' + 'a';
        }
        if (a[s[i]] > max_cnt) {
            max_cnt = a[s[i]];
            max_index = s[i];
        } else if (a[s[i]] == max_cnt && s[i] < max_index) {
            max_index = s[i];
            max_cnt = a[s[i]];
        }
    }
    printf("%c %d", max_index, max_cnt);
}
