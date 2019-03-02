#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >>t;

    while(t--){

        string s;
        cin >> s;
        int d;
        cin >> d;

        vector<int> v;

        for(char x: s){
            if (x != '0')
                v.push_back(x-'0');
        }

        int count_replaced = 0;

        for(vector<int>::iterator it = v.begin(); it!=v.end();){
            if(*it > d){
                v.erase(it);
                v.push_back(d);
                count_replaced++;
            }
            else{
                it++;
            }
        }

        int not_re = v.size() - count_replaced;
        // cout << not_re << endl;

        bool updated = true;

        while(updated){

            updated = false;
            int op =1;

            for(vector<int>::iterator it=v.begin(); it!=v.end();){

                // cout << *it << endl;

                if(op >= not_re){
                    break;
                }
                else if(*it > *(it+1)){
                    updated = true;
                    // cout << "Element : " << *it << endl;
                    v.erase(it);
                    v.push_back(d);
                }
                else{
                    it++;
                }
                op++;
            }

            
        }

        // for(vector<int>::iterator it=v.begin(); it!=v.end();){
            
        //     if(op > not_re){
        //         break;
        //     }
        //     else if( *it == v2[move_i]){
        //         move_i++;
        //         it++;
        //     }
        //     else if (*it != v2[move_i]){
        //         v.erase(it);
        //         v.push_back(d);
        //     }

        //     op++;
            
        // }

        for(int x: v){
            cout << x;
        }
        cout << endl;
    }

    return 0;
}