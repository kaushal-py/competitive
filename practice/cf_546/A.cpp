#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v;

    for(int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        v.push_back(r);
    }

    int k;
    cin >> k;
    vector<int>::iterator vi=lower_bound(v.begin(), v.end(), k);

    cout << n-(vi-v.begin()) << endl;

    return 0;
}