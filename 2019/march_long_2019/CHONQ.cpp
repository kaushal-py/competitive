#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        long long int n, k;
        cin >> n >> k;

        vector<long long int> v;

        for(int i=0; i<n; i++){
            long long int temp;
            cin >> temp;
            v.push_back(temp);
        }
        long long int i;
        for(i=0; i<n; i++){
            long long int sum = 0;
            for(long long int j=1; j<=n-i; j++){
                if(sum <= k){
                    sum += v[j+i-1]/j;
                    // cout << j+i-1 << ' ' << j << endl;
                    // cout << sum << ' ';
                }
                else{
                    break;
                }
            }
            if (sum <=k){
                cout << i+1 << endl;
                break;
            }
        }
        if(i == n){
            cout << n+1 << endl;
        }
    }
    return 0;
}