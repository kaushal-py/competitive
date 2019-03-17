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
        vector<long long int> v2;

        for(int i=0; i<n; i++){
            long long int temp;
            cin >> temp;
            v.push_back(temp);
            v2.push_back(temp/i);
        }

        long long int i;
        for(i=0; i<n; i++){
            long long int sum = 0;
            for(long long int j=1; j<=n-i; j++){
                cout << i << ' ';
                if(sum <= k){
                    sum += v[j+i-1]/j;
                    // cout << v[j+i-1]/j << ' ' << j << endl;
                    // cout << sum << ' ';
                }
                else{
                    // i=j+i-1;
                    // sum += v[j+i-1]/j;
                    break;
                }
            }

            // cout << "sum " << sum << endl;
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