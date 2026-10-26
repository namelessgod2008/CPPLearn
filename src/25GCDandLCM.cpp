#include <cstdio>

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

int main() {
    int a = 28;
    int b = 35;
    printf("%s%d%s%d","GCD",gcd(a,b),"LCM",lcm(a,b));
    return 0;
}

