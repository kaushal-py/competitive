#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        int positive = 0;
        int negative = 0;
        int zero = 0;

        cin >> n;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;

            if(temp > 0) positive++;
            else if(temp < 0) negative++;
            else if(temp == 0) zero++;
        }

        cout << max(positive+zero,negative+zero) << ' ';

        if(zero > 0){
            cout << 1 << endl;
        }
        else{
            if( negative == 0)
                cout << positive << endl;
            else if(positive == 0)
                cout << negative << endl;
            else
                cout << min(positive, negative) << endl;
        }

    }

    return 0;
}