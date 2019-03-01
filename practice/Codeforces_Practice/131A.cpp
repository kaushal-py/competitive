#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isCapital(char c){
    if (c>='A' && c<='Z') return true;
    else return false;
}

char changeCap(char c){
    if(isupper(c)) return tolower(c);
    else return toupper(c);
}

int main(){

    string s;
    cin >> s;

    if(all_of(s.begin()+1, s.end(), isCapital)){
        for(char c:s) cout << changeCap(c);
        cout << endl;
    }
    else cout << s << endl;

    return 0;
}