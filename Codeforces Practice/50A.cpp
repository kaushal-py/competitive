#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll m,n;

int main(){
    cin >> m >> n;
    ll ans = (m/2 * n) + (m%2 * n/2);
    cout << ans;
}