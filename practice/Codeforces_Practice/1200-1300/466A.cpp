#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n,m,a,b;
    cin >> n >>m >> a >> b;
    int mi = 1 << 30;
    // cout << mi << endl;

    for(int y=0; y<=(n/m+1); y++){
        int x = n-m*y;
        x = max(x,0);

        int rub=a*x+b*y;
        mi = min(mi, rub);
    }

    cout << mi << endl;

    return 0;
}