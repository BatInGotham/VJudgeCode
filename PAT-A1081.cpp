// PAT-A1081

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

struct Fraction {
    long long up = 0, down = 0;
};

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a%b);
}

Fraction reduction(Fraction result)
{
    if (result.down < 0) {
        result.down *= -1;
        result.up *= -1;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), result.down);
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction a, Fraction b)
{
    Fraction result;
    result.up = a.up * b.down + a.down * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

int main()
{
    int n;
    scanf("%d", &n);
    Fraction f;
    scanf("%lld/%lld", &f.up, &f.down);
    for(int k = 1; k < n; k++) {
        Fraction t;
        scanf("%lld/%lld", &t.up, &t.down);
        f = add(f, t);
    }
    f = reduction(f);
    if(f.down == 1)
        printf("%lld\n", f.up);
    else if(abs(f.up) > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
    return 0;
}
