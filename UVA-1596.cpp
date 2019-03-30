// UVA-1596
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <sstream>
using namespace std;

map<char,int> array_size;
map<pair<char, int>, int> array_value;

bool find_bug(string str)
{
    int pos = -1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '[' || str[i] == ']')
            str[i] = ' ';
    }
    stringstream ss(str);
    string token[80];
    int n = 0;
    while(ss >> token[n]) {
        if(token[n][0] == '=')
        {
            pos = n;
            token[n] = token[n].substr(1);
        }
        n++;
    }
    if(pos == -1) {
        array_size[token[0][0]] = stoi(token[1], 0, 10);
        return false;
    }
    int value, index;
    for(int i = n-1; i > 0; i--) {
        if(isalpha(token[i][0])) {
            if(array_value.find(make_pair(token[i][0], index)) == array_value.end()) {
                return true;
            }
            index = array_value[make_pair(token[i][0], index)];
        }
        else {
            if(i == pos-1)
                value = index;
            index = stoi(token[i], 0, 10);
        }
    }
    if(array_size.find(token[0][0]) != array_size.end() && index >= array_size[token[0][0]]) {
        return true;
    } else {
        array_value[make_pair(token[0][0], index)] = value;
    }
    return false;
}

int main()
{
    string str[1010];
    while(cin >> str[0] && str[0] != ".") {
        array_size.clear(); array_value.clear();
        int n = 1;
        while(cin >> str[n] && str[n] != ".") n++;
        int i;
        for(i = 0; i < n; i++) {
            if(find_bug(str[i])) {
                printf("%d\n", i+1);
                break;
            }
        }
        if(i == n)
            printf("0\n");
    }
    return 0;
}
