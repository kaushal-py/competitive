#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    string srev;
    cin >> s >> srev;

    string::iterator its = s.begin();
    string::reverse_iterator itsrev = srev.rbegin();

    bool flag = true;
    for(;its != s.end() && itsrev != srev.rend(); its++, itsrev++){
        if(*its != *itsrev) flag=false;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}