#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){

    string s;
    cin >> s;
    int caps;
    for(char c:s){
        if(isupper(c)) caps++;
    }
    if (caps <= s.length()/2){
        for(char c:s) cout << (char)tolower(c);
    }
    else{
        for(char c: s) cout << (char)toupper(c);
    }
    cout << endl;
    return 0;
}