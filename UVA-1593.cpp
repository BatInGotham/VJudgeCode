// UVA-1593
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int MaxL[180];
vector<string> word[1010];

int main()
{
    memset(MaxL, -1, sizeof(MaxL));
    string tmp;
    int i=0;
    while(getline(cin,tmp)) {
        stringstream ss(tmp);
        while(ss >> tmp) {
            word[i].push_back(tmp);
            if((int)(tmp.length()) > MaxL[word[i].size()-1]) {
                MaxL[word[i].size()-1] = tmp.length();
            }
        }
        i++;
    }
    for(int k = 0; k < i; k++) {
        for (int j = 0; j < word[k].size(); j++) {
            int len = word[k][j].length();
            cout << word[k][j];
            for (int m = 0; m <= MaxL[j] - len && j!=word[k].size()-1; m++) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
