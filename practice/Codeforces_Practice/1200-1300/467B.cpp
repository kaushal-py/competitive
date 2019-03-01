#include <iostream>
using namespace std;

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    unsigned int a[m+1];
    for(int i=0; i<=m; i++){
        cin >> a[i];
    }

    int friends = 0;

    for(int i=0; i<m; i++){
        unsigned int exor;
        exor=a[i]^a[m];
        int count=0;
        for(int j=0; j<n; j++){
            // cout << a[i] << ' ' << exor << " Bit val: "<< exor%2 << endl;
            if(exor%2 == 1){
                count++;
            }
            exor >>= 1;
        }
        // cout << "Count : " << count << endl;
        if (count <= k) friends++;
    }
    
    cout << friends << endl;

    return 0;
}