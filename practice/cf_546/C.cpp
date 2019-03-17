#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> s[n+m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;
            s[i+j].push_back(temp);
        }
    }

    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;

            if(find(s[i+j].begin(), s[i+j].end(), temp) == s[i+j].end()){
                flag = false;
            }
            else{
                s[i+j].erase(find(s[i+j].begin(), s[i+j].end(), temp));
            }
        }
    }

    for(int k=0; k<n+m; k++){
        if(s[k].size() != 0) flag=false;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}