#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int k, n, w;

    cin >> k >> n >> w;

    int total = w*(2*k+(w-1)*k)/2;

    cout << max( total - n, 0) << endl;

    return 0;
}