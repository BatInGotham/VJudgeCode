// PAT-A1035
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct User{
    string name;
    string pass;
    bool print;
} user[1010];

int main()
{
    int N;
    int cnt=0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> user[i].name >> user[i].pass;
        user[i].print = false;
        for(int j = 0; j < user[i].pass.length(); j++) {
            switch(user[i].pass[j]) {
                case '1': user[i].pass[j]='@'; user[i].print=true; break;
                case '0': user[i].pass[j]='%'; user[i].print=true; break;
                case 'l': user[i].pass[j]='L'; user[i].print=true; break;
                case 'O': user[i].pass[j]='o'; user[i].print=true; break;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(user[i].print)
            cnt++;
    }
    if(cnt == 0) {
        if(N == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", N);
        }
    } else {
        cout << cnt << endl;
        for(int i = 0; i < N; i++) {
            if(user[i].print) {
                cout << user[i].name << " " << user[i].pass << endl;
            }
        }
    }
}
