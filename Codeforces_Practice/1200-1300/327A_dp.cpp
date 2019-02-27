#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n], b[n];
    int s=0;

    for(int i=0; i<n; i++){
        cin >> a[i];
        s+=a[i];
        if(a[i]) b[i] = -1;
        else b[i] = 1;
    }

    int m=b[0];
    int cur=b[0];
    for(int i=1; i<n; i++){
        if(cur < 0) cur=0;
        cur+=b[i];
        m=max(cur,m);
    }

    cout << s+m << endl;

    
    return 0;
}