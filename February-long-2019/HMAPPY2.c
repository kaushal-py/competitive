#include <stdio.h>

int gcd(int u, int v){
    int shift;

    if (u == 0) return v;
    if (v == 0) return u;
 
    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1; v >>= 1;
    }
 
    while ((u & 1) == 0) u >>= 1;
    do {
        while ((v & 1) == 0) v >>= 1;
        if (u > v) {
            int t = v; v = u; u = t;
        }
       
        v = v - u;
    } while (v != 0);

    return u << shift; 
}

int main(void){

    int t;
    long long int n, k, lcm;
    int a, b;

    scanf("%d", &t);

    while(t--){

        scanf("%lld %d %d %lld", &n, &a, &b, &k);

        lcm = (1LL*a*b)/gcd(a, b);
        if (n/a + n/b - (2LL*n/lcm) >= k ) printf("Win\n");
        else printf("Lose\n");
    }

    return 0;
}