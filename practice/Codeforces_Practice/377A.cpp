#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector <int> v;

    for(int i=0; i<m; i++){
        int t1;
        cin >> t1;
        v.push_back(t1);
    }

    sort(v.begin(), v.end());

    int min_diff = 1001;
    for(vector<int>::iterator it = v.begin(); (it+n-1) != v.end(); it++){
        if((*(it+n-1) - *it) < min_diff){
            min_diff = (*(it+n-1) - *it);
        }
        //cout << "it, it+n-1: " << *it << *(it+n-1)  << endl;
    }

    cout << min_diff << endl;

    return 0;
}