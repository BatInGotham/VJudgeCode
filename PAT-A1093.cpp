// PAT-A1093
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cntP = 0;
    int cntT = 0;
    int p[100010];
    int t[100010];
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'P')
            cntP++;
        if(s[i] == 'A')
            p[i] = cntP;
        else
            p[i] = 0;
    }
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == 'T')
            cntT++;
        if(s[i] == 'A')
            t[i] = cntT;
        else
            t[i] = 0;
    }
    long long sum = 0;
    for(int i = 0; i < s.length(); i++) {
        sum += p[i] * t[i];
    }
    cout << sum % 1000000007;
}
