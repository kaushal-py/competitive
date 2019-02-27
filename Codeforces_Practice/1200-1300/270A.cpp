#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int t;
    cin >> t;
    set<int> s;

    double angle=0;
    int n=3;
    while(angle < 179){
        double intpart;
        angle=(180.0*(n-2))/n;
        //cout << n << ' ' << angle << endl;

        if(modf(angle, &intpart) == 0){
            s.insert(angle);
        }
        n++;
    }
    // for(int x: s) cout << x << ' ';
    // cout << endl;
    while(t--){
        int temp;
        cin >> temp;
        if(s.find(temp)!=s.end()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}