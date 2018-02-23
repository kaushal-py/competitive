#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

string s;
int main(){

    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for(int i=0; i<s.length(); i++){
        if (strchr("aeyiou", s[i]) == NULL){
            cout << "." << s[i];
        }
    }
}