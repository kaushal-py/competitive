#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int lcm(int a, int b){

    return (a*b)/__gcd(a,b);
}

int main(){
    
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    int c=0;
    for(int i=1; i<=d; i++){
        if(i%k==0||i%l==0||i%m==0||i%n==0){
            c++;
        }

    }
    cout << c << endl;
    return 0;
}