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
    solve_t();
    
}

void solve(){


}

void solve_t(){
    
    int t;
    cin >> t;

    while(t--){

        long long int a;
        cin >> a;

        long long profit=0;
        int day=1;
        long long c=1;
        bool flag1, flag2;
        int d1, d2;

        flag1=flag2=true;

        while(1){
            long long cp = a-c;
            if(flag1 && cp <= 0){
                flag1=false;
                d2=day-1;
            }
            profit += cp;
            cout << day << " " << cp << " " << profit << endl;
            if(profit <= 0){
                d1=day-1;
                flag2=false;
            }
            if(!flag2){
                break;
            }

            day++;
            c <<= 1;
            // cout << c << endl;
            // if(day==40) break;
        }    

        cout << d1 << " " << d2 << endl;    



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
