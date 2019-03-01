// PAT-A1038
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int N;
string num[10010];

bool cmp(string s1, string s2) {
    return s1+s2 < s2+s1;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num+N, cmp);
    string res = "";
    for (int i = 0; i < N; i++) {
        res += num[i];
    }
    while (res.size() != 0 && res[0] == '0') {
        res.erase(res.begin());
    }
    if (res.size() == 0)
        cout << "0";
    else
        cout << res;
    return 0;
}
