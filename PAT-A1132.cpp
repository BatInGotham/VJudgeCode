// PAT-A1132
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    while(N--) {
        std::string num;
        std::cin >> num;
        std::string num1, num2;
        int length = num.length() / 2;
        num1 = num.substr(0, length);
        num2 = num.substr(length, length);
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        int n = stoi(num);
        if(n1 * n2 == 0 || n % (n1 * n2) != 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
