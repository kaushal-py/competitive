#include <iostream>
using namespace std;

#define ll long long

ll n;
int main(){
    
    string s;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s;

        ll l = s.size();

        if( l <= 10){
            cout << s << endl;
        }else{
            cout << s[0] << l-2 << s[l-1] << endl;
        }
    }
}