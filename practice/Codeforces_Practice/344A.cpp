#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int temp;
    cin >> temp;
    int prev,cur;
    prev = temp;
    int groups = 1;
    for(int i=0; i< n-1; i++){
        cin >> temp;
        cur = temp;
        if(cur != prev){
            groups++;
        }
        prev=cur;
    }
    cout << groups << endl;
    return 0;
}