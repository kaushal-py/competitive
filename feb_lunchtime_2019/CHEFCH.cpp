#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve_t();

int main(){

    // solve_nvt();
    // solve();
    // solve_t();
    
}

void solve(){


}

void solve_t(){
    
    int t;
    cin >> t;

    vector<int> v1[300000];

    while(t--){

        int n,k;
        cin >> n >> k;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;

            v1[temp].push_back(i);
        }

        

    }
}

void solve_nvt(){

    int t;
    cin >> t;
    
    while(t--){
        int i,j,k,n;
        cin >> n;

        vector<int> v;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

    }
}
