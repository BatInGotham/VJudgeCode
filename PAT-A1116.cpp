// PAT-A1116
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int Rank[10010];

bool isPrime(int n) {
    int sqt = (int)sqrt(n*1.0);
    for(int i = 2; i <= sqt; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < 10010; i++) {
        Rank[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        Rank[num] = i+1;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int id;
        cin >> id;
        if(Rank[id] == 0) {
            printf("%04d: Are you kidding?\n", id);
        } else if(Rank[id] == -1) {
            printf("%04d: Checked\n", id);
        } else {
            int r = Rank[id];
            if(r == 1) {
                printf("%04d: Mystery Award\n", id);
            } else if(isPrime(r)) {
                printf("%04d: Minion\n", id);
            } else {
                printf("%04d: Chocolate\n", id);
            }
            Rank[id] = -1;
        }
    }
}
