// PAT-A1120
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int N;
int id[100];

int main()
{
    memset(id, 0, 100);
    cin >> N;

    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        int total = 0;
        while(num > 0) {
            total += num % 10;
            num /= 10;
        }
        id[total]++;
    }
    int cnt = 0;
    bool flag = true;
    for(int i = 0; i < 100; i++) {
        if(id[i] >= 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < 100; i++) {
        if(id[i] >= 1 && flag) {
            cout << i;
            flag = false;
        } else if(id[i] >= 1){
            cout << " " << i;
        }
    }
}
