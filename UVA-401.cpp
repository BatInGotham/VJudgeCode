#include <iostream>
#include <cstdio>

using namespace std;

const char * msg[] = {"not a palindrome.", "a regular palindrome.", "a mirrored string.", "a mirrored palindrome."};
const char * rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char com(char ch)
{
    if(isalpha(ch)) return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char s[30];
    while(scanf("%s", s) == 1)
    {
        int len = strlen(s);
        int p = 1, m = 1;
        for(int i = 0; i < (len+1) / 2; i++)
        {
            if (s[i] != s[len - 1 - i]) p = 0;
            if (com(s[i]) != s[len - 1 - i]) m = 0;
        }
        printf("%s -- is %s\n\n", s, msg[m*2+p]);
    }
    return 0;
}
