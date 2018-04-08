#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t;

int main(){
    cin >> t;

    while(t--){
        cin >> n;
        int mixes = 0;

        ll arr[n];

        for(int i=0; i<n; i++) cin >> arr[i];

        sort(arr, arr+n);

        for(int i=1; i<n; i++) if(arr[i] == arr[i-1]) mixes++;

        cout << mixes << endl;
    }
}