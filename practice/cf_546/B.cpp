#include <iostream>
using namespace std;

int main(){

    int n , k;

    cin >> n >> k;

    int total = 0;

    if (k-1 >= n-k){
        total += 2*(n-k) + k-1;
    }
    else{
        total += 2*k-2+n-k;
    }
    total += n;
    total += n+1;

    cout << total << endl;

    return 0;
}