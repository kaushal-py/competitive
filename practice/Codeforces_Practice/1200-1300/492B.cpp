#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    double m=max(v[0], k-v[n-1]);

    for(int i=0; i<n-1; i++){
        m=max((v[i+1]-v[i])/2.0, m);
    }

    cout << fixed << m << endl;



    return 0;
}