#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
    int testn = 0;
    scanf("%d", &testn);
//    getchar();getchar();
    while(testn--) {
        char s[100];
        std::cin >> s;
        int l = strlen(s);
        int res = l;
        for(int j = 1; j <= (l+1)/2; j++)  {
            if(l % j != 0)
                continue;
            bool foo = true;
            for(int k = 0; k < l; k++)  {
                if(s[k] != s[k%j])  {
                    foo = false;
                    break;
                }
            }
            if (foo)  {
               res = j;
               break;
            }
        }
        printf("%d\n", res);
        if(testn != 0)
            printf("\n");
    }
    return 0;
}
