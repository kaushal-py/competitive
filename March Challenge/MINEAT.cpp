#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t;

bool check(ll arr[], ll ans, int h, int n){
    bool flag = true;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + (arr[i] + ans - 1) / ans;
        if( sum > h) flag = false;
    }
    return flag;
}

int calc(ll arr[], ll start, ll end, int h, int n){
    
    if(start == end) return start;
    
    if(end - start == 1){
        if(check(arr, start, h, n)) return start;
        else return end;
    }
    
    ll mid = (start + end +1)/2;

    if(check(arr, mid, h, n) == true){
        return calc(arr, start, mid, h, n);
    }else{
        return calc(arr, mid+1, end, h, n);
    }
}

int main(){
    cin >> t;
    int h, ans;

    while(t--){
        cin >> n >> h;
        ll arr[n];

        for(int i=0; i<n; i++) cin >> arr[i];

        cout << calc(arr, 1, *max_element(arr, arr+n), h, n) << endl;
    }
}