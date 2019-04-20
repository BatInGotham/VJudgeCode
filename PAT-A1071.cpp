// PAT-A1071
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string, int> word_count;

int main()
{
    string input;
    getline(cin, input);
    for(int i = 0; i < input.length(); i++) {
        if(input[i] <= 'Z' && input[i] >= 'A') {
            input[i] = input[i] - 'A' + 'a';
        }
        if(input[i] <= 'z' && input[i] >= 'a' || input[i] <= '9' && input[i] >= '0') {
            // do nothing
        } else {
            input[i] = ' ';
        }
    }
    stringstream ss(input);
    while(ss >> input) {
        map<string, int>::iterator it;
        it = word_count.find(input);
        if(it == word_count.end()) {
            word_count.insert(make_pair(input, 1));
        } else {
            word_count[input]++;
        }
    }
    int max = 0;
    auto it = word_count.begin();
    for(it = word_count.begin(); it != word_count.end(); it++) {
        if(it->second > max) {
            max = it->second;
        }
    }
    for(it = word_count.begin(); it != word_count.end(); it++) {
        if(it->second == max) {
            cout << it->first << " " << it->second;
            return 0;
        }
    }
}
