#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    bool even = (a[0]%2 + a[1]%2 + a[2]%2) < 2;

    for(int i=0; i<n; i++){
        if (a[i]%2 == even){
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}