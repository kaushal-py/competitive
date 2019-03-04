#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;

int occ[2001][2001];


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> arr;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        // Precalculate all occurences of elements
        memset(occ, 0, sizeof(occ[0][0]) * 2001 * 2001);
        occ[arr[0]][1] = 1;

        for(int j=1; j<=2000; j++){
            for(int i=2;i<=n; i++){
                int temp_occ = occ[j][i-1];
                if(arr[i-1] == j){
                    occ[j][i] = temp_occ+1; 
                }
                else{
                    occ[j][i] = temp_occ;
                }
            }
        }


        // for(int j=0; j<=10; j++){
        //     cout << j << ": ";
        //     for(int i=0; i<=n; i++){
        //         cout << occ[j][i] << ' ';
        //     }
        //     cout << endl;
        // }
        long long int count = 0;
        for(int i=0; i<n; i++){
            // for(int k=0; k<i; k++){
            //     cout << "  ";
            // }

            // set<int> s;
            for(int j=i; j<n; j++){

                // cout << i << ' ' <<  j << endl;
         
                int m = ceil((double)k/(j-i+1));
                // cout << "m=" << m << endl;
                int pos = (k-1)/m;
                // cout << "Pos =" << pos << endl;
                vector<int> v2(arr.begin()+i, arr.begin()+j+1);

                // for(int x:v2){
                //     cout << x << ' ';
                // }
                // cout << endl;

                sort(v2.begin(),v2.end());
                int X = v2[pos];
                // cout << "X = " << X << endl;
                int F = occ[X][j+1] -occ[X][i] ;
                cout  << pos << ' ';
                // cout  << occ[F][j+1] -occ[F][i] << ' ';

                if(occ[F][j+1] -occ[F][i] > 0){
                    // cout << "BEautiful" << endl;
                    count++;
                }  

                // cout << "---------------------" << endl;              

            }
            cout << endl;
        }
        cout << count << endl;
    }
    return 0;
}

