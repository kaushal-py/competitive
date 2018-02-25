#include <iostream>
#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;

#define ll long long

ll n, d;
string s;

int main(){
    cin >> n >> d;

    ll arr[n];

    int removed[n] = {0};

    int countRemoved = 0;

    for(ll i=0; i<n; i++) cin >> arr[i];

    for(ll i=0; i<n; i++){
        if(removed[i] == 1) continue;
        else{
            for(ll j=i+1; j<n; j++){
                if(removed[j] == 1) continue;
                else{
                    if(abs(arr[j] - arr[i]) > d){
                        removed[j] = 1;
                        countRemoved++;
                    }
                }
            }
        }
    }

    cout << countRemoved;
}