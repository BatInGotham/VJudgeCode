#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int testn = 0;
    std::cin >> testn;
    for(int i = 0; i < testn; i++)
    {
        char s[100];
        scanf("%s", s);
        int cnt = 1;
        int sum = 0;
        for(int j = 0; j < strlen(s); j++)
        {
            if(s[j] == 'O')
                sum += cnt++;
            if(s[j] == 'X') {
                cnt = 1;
            }
        }
        printf("%d\n", sum);
    }
}
