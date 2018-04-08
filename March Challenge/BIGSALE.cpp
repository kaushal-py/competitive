#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t;

int main(){
    cin >> t;

    while(t--){
        cin >> n;

        double loss = 0;

        ll p, q, d;

        for(int i=0; i<n; i++){
            cin >> p >> q >> d;
            loss += (p - (p*(1+d*0.01)*(1-d*0.01)))*q;
        }

        printf("%lf\n", loss);
    }    
}