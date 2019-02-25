#include <iostream>
using namespace std;

int main(){

    int n, a,b,c;

    cin >> n >> a >> b >> c;

    int mem[n+1];
    fill_n(mem,n+1, -100);
    mem[0] = 0;

    for(int i=1; i<n+1; i++){
        // cout << mem[i] << ' ';
        int m=-100;
        if(i-a>=0) m = mem[i-a];
        if(i-b>=0) m = max(m, mem[i-b]);
        if(i-c>=0) m = max(m, mem[i-c]);
        
        if (m != -100)
            mem[i] = m+1;
        // cout << mem[i] << ' ';
    }

    cout << mem[n] << endl;
    return 0;
}