#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    vector<int> vecs[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            int temp;
            cin >> temp;
            vecs[i].push_back(temp);
        }
    }

    bool flag=false;

    for(int j=0; j<3; j++){
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= vecs[i][j];
        }

        if (sum !=0){
            flag=true;
            break;
        }
    }

    if (flag == false) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}