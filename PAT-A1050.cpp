// PAT-A1050

#include <iostream>
#include <cstdio>
#include <cstring>

char s[10010];
bool ch[256] = {false};
char ban[10010];

int main()
{
    std::cin.getline(s, 10005);
    std::cin.getline(ban, 10005);
    for (int i = 0; i < strlen(ban); i++) {
        ch[ban[i]] = true;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (ch[s[i]] == false) {
            printf("%c", s[i]);
        }
    }
    return 0;
}
