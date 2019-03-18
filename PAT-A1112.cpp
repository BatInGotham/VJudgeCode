// PAT-A1112
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool keyboard[256];
int k;
vector<char> dumpChar;

bool dump(string s, int pos) {
    for(int i = 1; i < k; i++) {
        if(s[pos] != s[pos+i])
            return false;
    }
    return true;
}

int main()
{
    cin >> k;
    string in;
    cin >> in;
    for(int i = 0; i < 256; i++) {
        keyboard[i] = false;
    }
    for(int i = 0; i < in.length()-k+1; ) {
        if(dump(in, i)) {
            i += k;
        } else {
            keyboard[in[i]] = true;
            i++;
        }
    }
    for(int i = 0; i < in.length()-k+1; ) {
        if(dump(in, i) && !keyboard[in[i]]) {
            auto iter = find(dumpChar.begin(), dumpChar.end(), in[i]);
            if(iter == dumpChar.end()) {
                dumpChar.push_back(in[i]);
                continue;
            }
            i+=k;
        }
        else
            i++;
    }
    for(auto iter = dumpChar.begin(); iter != dumpChar.end(); iter++) {
        cout << (*iter);
    }
    cout << endl;
    for(int i = 0; i < in.length(); ) {
        if(i < in.length()-k+1 && dump(in, i) && !keyboard[in[i]]) {
            cout<<in[i];
            i+=k;
        } else {
            cout<<in[i];
            i++;
        }
    }
    return 0;
}
