#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int m=0;
    for(int i=0;i<n; i++){
        for(int j=i; j<n; j++){
            int c=0;
            for(int k=0; k<i; k++) c+=arr[k];
            for(int k=i; k<=j; k++) c+=(1-arr[k]);
            for(int k=j+1; k<n; k++) c+=arr[k];

            if (c>m) m=c;
        }
    }
    cout << m << endl;

    return 0;
}