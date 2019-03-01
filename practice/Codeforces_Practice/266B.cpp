#include <iostream>
using namespace std;

void swap(char * c1, char * c2){
    char t1 = *c1;
    *c1 = *c2;
    *c2 = t1;
}

int main(){

    int n, t;
    cin >> n >> t;

    char arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    while(t--){
        for(int i=0; i<n-1; i++){
            if(arr[i] == 'B' && arr[i+1] == 'G'){
                swap(&arr[i], &arr[i+1]);
                i++;
            }
        }
    }

    for(int i=0; i<n; i++) cout << arr[i];

    cout << endl;

    return 0;
}