// PAT-A1152
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

bool isPrime(long long num)
{
    if(num <= 1)
        return false;
    long long sqt = sqrt(num * 1.0);
    for(int i = 2; i <= sqt; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int length, number;
    scanf("%d%d", &length, &number);
    char str[1010];
    scanf("%s", str);
    char* tmp;
    for(int i = 0; i+number <= length; i++) {
        // start bit
        tmp = str+i;
        long long num = 0;
        for(int j = 0; j < number; j++) {
            num = num * 10 + tmp[j] - '0';
        }
        if(isPrime(num)) {
            int zero = number;
            long long tmp = num;
            while(tmp != 0) {
                tmp /= 10;
                zero--;
            }
            for(int i = 0; i < zero; i++)
                printf("0");
            printf("%lld", num);
            return 0;
        }
    }
    printf("404");
    return 0;
}
