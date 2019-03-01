#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    int max_len = 0;

    for(int i=0; i<n;){
        int start, curr;
        start = curr = i;
       /// cout << "start=" << start << endl;

        while(curr+1<n && arr[curr] <= arr[curr+1]) curr++;

        if(curr - start + 1 > max_len){
            max_len = curr-start+1;
        }

        i=curr+1;
       // cout << "i=" << i << endl;
    }

    cout << max_len << endl;
    return 0;
}