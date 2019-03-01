#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int temp, b[n];

    for(int i=0; i<n; i++){
        cin >> temp;
        b[temp-1] = i+1;
    }

    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}