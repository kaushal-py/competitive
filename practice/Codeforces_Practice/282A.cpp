#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, x;
string s;

int main(){
    cin >> n;
    x=0;
    while(n--){
        cin >> s;
        if(s[1] == '+') x++;
        else x--;
    }
    cout << x;
}