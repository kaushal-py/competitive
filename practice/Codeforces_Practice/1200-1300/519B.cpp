#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a, b,c;
    vector<int> v(1);

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n-1; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    sort(b.begin(), b.end());

    for(int i=0; i<n-2; i++){
        int temp;
        cin >> temp;
        c.push_back(temp);
    }
    sort(c.begin(), c.end());

    set_difference(a.begin(),a.end(), b.begin(), b.end(), v.begin());
    cout << v[0] << endl;

    set_difference(b.begin(),b.end(), c.begin(), c.end(), v.begin());
    cout << v[0] << endl;


    return 0;
}