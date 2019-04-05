// PAT-A1077
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s[110];
string ret;
int N;
int main()
{
    cin >> N;
    getchar();
    for(int i = 0; i < N; i++) {
        getline(cin, s[i]);
        reverse(s[i].begin(), s[i].end());
    }
    int length = 0;

    for(int i = 0; i < s[0].length(); i++) {
        bool foo = true;
        for(int j = 1; j < N; j++) {
            if(s[j][i] != s[0][i]) {
                foo = false;
                break;
            }
        }
        if(foo) {
            if(s[0][i] != '~') {
                length = i + 1;
                ret = s[0].substr(0, length);
            }
        } else {
            break;
        }
    }
    if(!length) {
        cout << "nai";
    } else {
        reverse(ret.begin(), ret.end());
        while(ret[0] == ' ') {
            ret = ret.substr(1);
        }
        cout << ret;
    }
}
