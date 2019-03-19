// PAT-A1053
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string num;
    string e;
    bool neg = false;
    int e_pos = -1;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'E') {
            e_pos = i;
            break;
        }
    }
    if(s[0] == '-') {
        neg = true;
    }
    num = s.substr(1, 1);
    num += s.substr(3, e_pos-3);
//    cout << num << endl;
    e = s.substr(e_pos+1);
    int ee = stoi(e);
//    cout << ee << endl;
    if(neg)
        cout << "-";
    if(ee == -1) {
        cout << "0." << num;
    } else if(ee < -1) {
        int cnt = 0-ee-1;
        cout << "0.";
        for(int i = 0; i < cnt; i++)
            cout << "0";
        cout << num;
    } else {
        int cnt = ee+1;
        int len = num.length();
        if(len <= cnt) {
            cout << num;
            for(int i = 0; i < cnt-len; i++)
                cout << "0";
        } else {
            cout << num.substr(0, cnt) << "." << num.substr(cnt);
        }
    }
}
