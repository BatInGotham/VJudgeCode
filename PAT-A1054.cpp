// PAT-A1054
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int M, N;
int color[100000000];
int Max = 0;
int col = 0;

int main()
{
    memset(color, 0, 1000000);
    cin >> M >> N;
    int num;
    for(int i = 0; i < M*N; i++){
        scanf("%d", &num);
        color[num]++;
        if(color[num] > Max) {
            Max = color[num];
            col=num;
        }
    }
    cout << col;
}
