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
    return b == 0 ? a : gcd(abs(b), a%b);
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
        int d = gcd(abs(result.up), abs(result.down));
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

Fraction minus(Fraction a, Fraction b)
{
    Fraction result;
    result.up = a.up * b.down - b.up * a.down;
    result.down = a.down * b.down;

    return reduction(result);
}

Fraction mult(Fraction a, Fraction b)
{
    Fraction result;
    result.up = a.up * b.up;
    result.down = a.down * b.down;

    return reduction(result);
}

Fraction divide(Fraction a, Fraction b)
{
    Fraction result;
    result.up = a.up * b.down;
    result.down = a.down * b.up;

    return reduction(result);
}

void show(Fraction f)
{
    f = reduction(f);
    if(f.up < 0)
        printf("(");
    if(f.down == 1)
        printf("%lld", f.up);
    else if(abs(f.up) > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
    if(f.up < 0)
        printf(")");
}

int main()
{
    Fraction f;
    Fraction g;
    scanf("%lld/%lld %lld/%lld", &f.up, &f.down, &g.up, &g.down);
    // Add
    Fraction A = add(f, g);
    show(f);
    printf(" + ");
    show(g);
    printf(" = ");
    show(A);
    printf("\n");
    // Minus
    Fraction B = minus(f, g);
    show(f);
    printf(" - ");
    show(g);
    printf(" = ");
    show(B);
    printf("\n");
    // Multiple
    Fraction C = mult(f, g);
    show(f);
    printf(" * ");
    show(g);
    printf(" = ");
    show(C);
    printf("\n");
    // Divide
    Fraction D = divide(f, g);
    show(f);
    printf(" / ");
    show(g);
    printf(" = ");
    if(g.up == 0)
        printf("Inf");
    else
        show(D);
    return 0;
}
