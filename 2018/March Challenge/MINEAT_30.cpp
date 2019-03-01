#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t;

int main(){
    cin >> t;
    int h, ans;

    while(t--){
        cin >> n >> h;
        ll arr[n];

        for(int i=0; i<n; i++) cin >> arr[i];

        int flag;
        int ans = (2*n-h-1 >= 0)?arr[2*n-h-1]:1;
        do{
            int sum = 0;
            flag = 0;
            for(int i=0; i<n; i++){
                sum = sum + (arr[i] + ans -1) / ans;
                if( sum > h) flag = 1;
            }
            ans++;
        }while(flag == 1);

        cout << (ans-1) << endl;
    }
}