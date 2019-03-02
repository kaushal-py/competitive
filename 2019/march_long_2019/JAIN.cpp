#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // map to store all subsets of subsets of aeiou
    map<string, vector<string>> m_big;

    char fullstring[] = "aeiou";

    // Precalculate all subsets
    for(int i=0; i<32 ; i++){
        string subset = "";
        for(int j=0; j<5; j++){
            if ((i & (1 << j)) != 0){
                subset+= fullstring[j];
            }
        }
        
        int len = subset.length();
        vector<string> stringset;
        for(int k=0; k<(int) pow(2, len); k++){
            string subsubset = "";
            for(int l=0; l<len; l++){
                if((k & (1 << l)) != 0){
                    subsubset+= subset[l];
                }
            }
            stringset.push_back(subsubset);
        }
        m_big[subset] = stringset;
    }

    while(t--){

        char fullstr[] = "aeiou";
        unordered_map<string, int> m;
        m.reserve(64);
        m.max_load_factor(0.25);

        int n;
        cin >> n;

        string sub[n];

        for(int i=0; i<n; i++){
            string temp;
            cin >> temp;
            int arr[5] = {0};

            for(char x: temp){
                if(x == 'a') arr[0] = 1;
                else if(x == 'e') arr[1] = 1;
                else if(x == 'i') arr[2] = 1;
                else if(x == 'o') arr[3] = 1;
                else if(x == 'u') arr[4] = 1;
            }

            
            if(arr[0] == 1) sub[i] += 'a';
            if(arr[1] == 1) sub[i] += 'e';
            if(arr[2] == 1) sub[i] += 'i';
            if(arr[3] == 1) sub[i] += 'o';
            if(arr[4] == 1) sub[i] += 'u';

            for(string s: m_big[sub[i]]){
                m[s]++;
            }

        }

        // unordered_map<string, int>::iterator mit;
        // for(mit = m.begin(); mit!=m.end(); mit++){
        //     cout << mit->first << "\t:\t" << mit->second << endl;
        // }

        long long int totalcount = 0;

        for(int i=0; i<n; i++){
            set<char> diff;
            set<char> s;

            int arr[5];
            fill_n(arr,5,1);

            for(char x: sub[i]){
                if(x == 'a') arr[0] = 0;
                else if(x == 'e') arr[1] = 0;
                else if(x == 'i') arr[2] = 0;
                else if(x == 'o') arr[3] = 0;
                else if(x == 'u') arr[4] = 0;
            }


            string diffstring = "";
            if(arr[0] == 1) diffstring += 'a';
            if(arr[1] == 1) diffstring += 'e';
            if(arr[2] == 1) diffstring += 'i';
            if(arr[3] == 1) diffstring += 'o';
            if(arr[4] == 1) diffstring += 'u';
            
            //cout << sub[i] << " :" << diffstring << endl; 
            if(diffstring.length() > 0)
                totalcount += m[diffstring];
            else{
                totalcount += n-1;
            }
        }
        cout << totalcount/2 << endl;
    }

    return 0;
}