#include <iostream>
using namespace std;

#define ll long long

int main(){
    ll n, m, a;

    cin >> n >> m >> a;

    if (n%a != 0)
        n = n + (a - n%a);
    if (m%a != 0)
        m = m + (a - m%a);

    ll ans = (n*m)/(a*a);

    cout << ans;
}