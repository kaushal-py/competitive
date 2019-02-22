#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int temp= n/5 + (n%5 != 0);
    cout << temp << endl;
    return 0;
}