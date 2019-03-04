// PAT-A1100
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string numToStr[170];
map<string, int> strToNum;

int main()
{
    for(int i = 0; i < 13; i++) {
        numToStr[i] = unitDigit[i];
        strToNum[unitDigit[i]] = i;
        numToStr[i*13] = tenDigit[i];
        strToNum[tenDigit[i]] = i*13;
    }
    for(int i = 1; i < 13; i++) {
        for(int j = 1; j < 13; j++) {
            string str = tenDigit[i] + " " + unitDigit[j];
            numToStr[i * 13 + j] = str;
            strToNum[str] = i*13+j;
        }
    }
    int N;
    scanf("%d%*c", &N);
    for(int i = 0; i < N; i++) {
        string str;
        getline(cin, str); // read a line instead of a string
        if(str[0] <= '9' && str[0] >= '0') {
            int num = 0;
            for(int j = 0; j < str.length(); j++) {
                num = num*10 + str[j]-'0';
            }
            cout << numToStr[num] << endl;
        } else {
            cout << strToNum[str] << endl;
        }
    }
    return 0;
}
