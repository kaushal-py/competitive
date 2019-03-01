#include <iostream>
using namespace std;

#define ll long long

int main(){
    ll i;

    cin >> i;

    if(i == 2){
        cout << "NO\n";
    }
    else if(i % 2 == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}