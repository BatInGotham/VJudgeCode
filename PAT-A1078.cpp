// PAT-A1078
#include <iostream>
#include <string>
using namespace std;

int M, N;

int main()
{
    cin >> M >> N;
    if(M <= 2) {
        M = 2;
    }
    for(int i = M; ;i++) {
        bool foo = true;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                foo = false;
                break;
            }
        }
        if(foo) {
            M = i;
            break;
        }
    }
    bool a[10020];
    for(int i = 0; i < M; i++) {
        a[i] = false;
    }
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        bool insert = false;
        int j;
        for(j = 0; j <= M; j++) {
            if(a[(j*j+num)%M] == false) {
                insert = true;
                a[(j*j+num)%M] = true;
                break;
            }
        }
        if(insert) {
            cout << (j*j+num)%M;
        } else {
            cout << "-";
        }
        if(i != N-1) {
            cout << " ";
        }
    }
}
