#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    cin >> s;

    bool is_first = true;
    bool is_space= true;
    for(int i=0; i<s.length();){

        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
            if(!is_first && is_space) cout << ' ';
            i+=3;
            is_space=false;
        }
        else{
            cout << s[i];
            i++;
            is_first=false;
            is_space=true;
        }
    }
    cout << endl;

    return 0;
}