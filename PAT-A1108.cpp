// PAT-A1108

#include <iostream>
#include <cstdio>
#include <string>

#define ERRNUM 2000
using namespace std;

int cnt = 0;
string arr[110];

double isLegal(string s) {
    // process negative symbol
    bool neg = false;
    if(s[0] == '-') {
        neg = true;
        s = s.substr(1);
    }
    int dot = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '.') {
            dot++;
            if(dot > 1)
                return ERRNUM;
            else if(s.length() - i > 3)
                return ERRNUM;
        } else if(s[i] > '9' || s[i] < '0')
            return ERRNUM;
    }
    double number = stod(s);
    if(number <= 1000 && number >= -1000)
        return (neg?-1:1)*number;
    else
        return ERRNUM;
}

int main()
{
    int N;
    double sum = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(isLegal(arr[i]) != ERRNUM) {
//            printf("LEGAL: %2f\n", stod(arr[i]));
            cnt++;
            sum += stod(arr[i]);
        } else {
//            printf("ILLEGAL: ");
//            cout << arr[i] << endl;
            cout << "ERROR: " << arr[i] << " is not a legal number" << endl;
        }
    }
    if(cnt == 0) {
        cout << "The average of 0 numbers is Undefined";
    } else if (cnt > 1){
        cout << "The average of " << cnt << " numbers is ";
        printf("%.2f", sum/cnt);
    } else {
        cout << "The average of 1 number is ";
        printf("%.2f", sum/cnt);
    }
}
