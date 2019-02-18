#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, x;
string s;

int main(){
    cin >> s;

    ll nums[(s.length()+1)/2];
    
    for(int i=0; i< s.length(); i+=2) nums[i/2] = s[i];

    sort(nums, nums+(s.length()+1)/2);

    for(int i=0; i< (s.length()+1)/2 - 1; i++) cout << (char)nums[i] << "+";
    cout << (char)nums[(s.length()+1)/2 - 1];
}