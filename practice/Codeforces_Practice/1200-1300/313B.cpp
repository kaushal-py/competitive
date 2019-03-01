#include <iostream>
using namespace std;

int main(){

    string s;
    cin >> s;
    
    int n = s.length();
    // cout << n << endl;
    int arr[n+1];
    fill_n(arr, n, 0);

    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            arr[i] = 1;
        }
    }
    
    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    int q;
    cin >> q;

    while(q--){

        int l,m;
        cin >> l >> m;

        cout << arr[m-1] - arr[l-1] << endl;
    }



    return 0;
}