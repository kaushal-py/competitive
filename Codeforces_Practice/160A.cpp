#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n ;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.rbegin(), v.rend());
    int total = accumulate(v.begin(), v.end(), 0);
    int sum = 0;
    
    int coins = 0;
    for(int x:v){
        sum += x;
        coins++;
        if(sum > total-sum) break;
    }

    cout << coins << endl;

    return 0;
}