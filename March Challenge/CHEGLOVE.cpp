#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t;

int main(){
    cin >> t;

    while(t--){
        cin >> n;

        ll hands[n], gloves[n];

        for(int i=0; i< n; i++) cin >> hands[i];
        for(int i=0; i< n; i++) cin >> gloves[i];

        int front = 1;
        int back = 1;

        for(int i=0; i<n; i++){
            if(hands[i] > gloves[i]) front = 0;
            if(hands[i] > gloves[n-i-1]) back = 0;
        }

        if (front == 1 && back == 1) cout << "both" << endl;
        else if (front == 1) cout << "front" << endl; 
        else if (back == 1) cout << "back" << endl;
        else cout << "none" << endl; 
        
    }    
}