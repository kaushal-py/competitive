#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, temp, solve;

int main(){
    cin >> n;
    while(n--){
        ll ones = 0;
        for(int i=0; i<3; i++){
            cin >> temp;
            if(temp == 1) ones++;
        }
        if(ones >= 2) solve++;
    }
    cout << solve << endl;
}