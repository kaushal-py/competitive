#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int ac=0, dc=0;

    for(int i=0; i<n; i++){
        char temp;
        cin >> temp;
        if (temp == 'A') ac++;
        else if (temp == 'D') dc++;    
    }

    if(ac > dc) cout << "Anton" << endl;
    else if (dc > ac) cout <<  "Danik" << endl;
    else cout << "Friendship" << endl;
    return 0;
}