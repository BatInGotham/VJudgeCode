#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int groupnum = 0;
    int size;
    cin >> size;
    int ans[1000];
    int request[1000];
    while (size != 0){
        groupnum++;
        printf("Game %d:\n", groupnum);
        // standard answer
        for(int i = 0; i < size; i++)
        {
            cin >> ans[i];
        }
        // request array
        while(true) {
            int A = 0, B = 0;
            for (int i = 0; i < size; i++) {
                cin >> request[i];
                if(request[i] == ans[i])
                    A++;
            }
            if(request[0] == 0)
                break;
            for (int d = 1; d < 10; d++) {
                int c1 = 0, c2 = 0;
                for (int k = 0; k < size; k++)  {
                    if(ans[k] == d) c1++;
                    if(request[k] ==d) c2++;
                }
                B += (c1 < c2)? c1: c2;
            }
            printf("    (%d,%d)\n", A, B-A);
        }
        cin >> size;
    }
    return 0;
}
