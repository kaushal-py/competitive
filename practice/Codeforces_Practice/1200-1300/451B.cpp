#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    int i=0;
    int start=n-1,end=n-1;
    while(i<n-1){
        if(a[i] > a[i+1]){
            start = i;
            break;
        }
        i++;
    }
    while(i<n-1){
        if(a[i] < a[i+1]){
            end = i;
            break;
        }
        i++;
    }
    // cout << start << '-' << end << endl;
    reverse(a.begin()+start, a.begin()+end+1);

    if( is_sorted(a.begin(),a.end())){
        cout << "yes" << endl;
        cout << start+1 << ' ' << end+1 << endl;
    }
    else{
        cout << "no" << endl;
    }

    return 0;
}