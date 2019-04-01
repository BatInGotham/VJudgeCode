// PAT-A1096
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int max = (int)sqrt(t)+1;
    int maxcnt = 1;
    int startsymbol = t;
    for(int i = 2; i <= max; i++) {
        int product = 1;
        int j;
        bool flag = false;
        for(j = i; j <= t; j++) {
            product *= j;
            if(t >= product && t % product == 0) {
                flag = true;
            } else {
                break;
            }
        }
        if(flag) {
            if(j-i>maxcnt|| (j-i==maxcnt&&i<startsymbol)) {
                maxcnt = j-i;
                startsymbol = i;
            }
        }
    }
    printf("%d\n", maxcnt);
    for(int i = 0; i < maxcnt; i++) {
        printf("%d", i+startsymbol);
        if(i != maxcnt-1)
            printf("*");
    }
}
