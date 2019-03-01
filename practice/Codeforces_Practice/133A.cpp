#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    string code;
    cin >> code;

    bool flag = false;
    for(char x:code){
        if( x=='H' || x=='Q' || x=='9'){
            flag=true;
            break;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}