#include <iostream>
using namespace std;

int bin_search(int a[], int low, int high, int key){

    int mid=(low+high)/2;

    if(key <= a[mid] && key > a[mid-1]){
        return mid;
    }
    else if(key <= a[mid]){
        bin_search(a, low, mid-1, key);
    }
    else{
        bin_search(a, mid+1, high, key);
    }   
}


int main(){

    int n;
    cin >> n;

    int a[n+1];
    int sum=0;
    a[0]=0;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        sum += temp;
        a[i] = sum;
        // cout << a[i] << ' ';
    }
    // cout << endl;

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        cout << bin_search(a,1,n,temp) << endl;
    }




    return 0;
}