#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    int testn = 0;
    std::cin >> testn;
    double tb[5] = {0, 12.01, 1.008, 16.00, 14.01};
    for(int i = 0; i < testn; i++)
    {
        double sum = 0;
        int lastElement = 0;
        int lastCnt = 1;
        char s[100];
        scanf("%s", s);
        bool has = false;
        for(int j = 0; j <= strlen(s); j++)
        {
            if(isalpha(s[j]))
            {
                sum += tb[lastElement] * lastCnt;
                switch(s[j]) {
                    case 'C': lastElement = 1; lastCnt = 1; has = false; break;
                    case 'H': lastElement = 2; lastCnt = 1; has = false; break;
                    case 'O': lastElement = 3; lastCnt = 1; has = false; break;
                    case 'N': lastElement = 4; lastCnt = 1; has = false; break;
                    default: break;
                }
//                if(j == strlen(s) - 1)
//                    sum += tb[lastElement] * lastCnt;
            }
            else if(s[j] <= '9' && s[j] >= '0')
            {
                if(has == false) {
                    lastCnt = s[j] - '0';
                    has = true;
                }
                else {
                    lastCnt = lastCnt*10 + s[j]-'0';
                }
//                if(j == strlen(s)-1)
//                    sum += tb[lastElement] * lastCnt;
            }
            else if(s[j] == '\0') {
                sum += tb[lastElement] * lastCnt;
            }
        }
        printf("%.3f\n", sum);
    }
}
