#include <iostream>
#include <algorithm>
using namespace std;

bool isLucky(long long int num){

    if (num == 0) return false;
    while(num > 0){
        int temp = num % 10;
        if(temp != 4 && temp != 7) return false;
        num = num /10;
    }
    return true;
}

int main(){

    string n;
    cin >> n;
    
    long long int lucky_count;

    lucky_count = count_if(n.begin(), n.end(), [](char c){
        if(c == '4' || c=='7') return true;
        else return false;
    });

    //cout << "Lucky count " << lucky_count << endl;

    if(isLucky(lucky_count)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    


    return 0;
}