#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, x;
string s;

int main(){
    cin >> s;
    
    char curr = s[0];
    int flag = 0;
    x=1;
    for(int i=1; i<s.length(); i++){
        if(curr == s[i]){
            x++;
        }
        else{
            curr = s[i];
            x = 1;
        }
        if(x == 7){
            flag = 1; break;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
}