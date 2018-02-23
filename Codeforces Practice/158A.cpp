#include <iostream>
using namespace std;

#define ll long long

ll n, k;
int main(){
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    ll temp;
    if(arr[k-1] <= 0){
        temp = k-1;
        while(temp >= 0 && arr[temp] <= 0) temp--;
        cout << temp+1 << endl;
    }else{
        temp = k-1;
        while(temp <= n && arr[temp] == arr[k-1]) temp++;
        cout << temp << endl;
    }

    
}