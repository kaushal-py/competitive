#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    long long n;
    cin >> n;

    vector<int> v;

    int max_diff = 0;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    max_diff = v[n-1]-v[0];

    long long int count = 0;

    if( max_diff > 0){
        vector<int>::iterator lower, upper;
    
        upper = upper_bound(v.begin(), v.end(), v[0]);
        lower = lower_bound(v.begin(), v.end(), v[n-1]);

        count += ((n-(long long)(lower-v.begin())) * (long long)((upper-v.begin()))); 
        cout << max_diff << ' ' << count << endl;
    }
    else{
        cout << 0 << ' ' << n*(n-1)/2 << endl;
    }
    return 0;
}