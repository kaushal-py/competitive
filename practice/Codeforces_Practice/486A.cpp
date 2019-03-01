#include <iostream>
using namespace std;

int main(){

    long long int n;
    cin >> n;
    long long int ans;
    if(n%2 != 0){
        ans = -1 + n/2*(-1);
    }
    else{
        ans = n - n/2;
    }
    cout << ans << endl;
    return 0;
}