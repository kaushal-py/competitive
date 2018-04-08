// C program to show segment tree operations like construction, query
// and update
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>
#include <math.h>

#define ll long long

int n, t;

void findSum(int arr1[], int arr2[], int ans[31]){
    if(arr1 == NULL) ans = arr2;
    if(arr2 == NULL) ans = arr1;

    for(int i=0; i<31; i++) ans[i] = arr1[i] + arr2[i];    
}

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range */
void getSumUtil(int st[][31], int ss, int se, int qs, int qe, int si, int countones[31])
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se) copy(st[si], st[si]+31, countones);

    // If segment of this node is outside the given range
    if (se < qs || ss > qe) return;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    int arr1[31], arr2[31];

    getSumUtil(st, ss, mid, qs, qe, 2*si+1, arr1);
    getSumUtil(st, mid+1, se, qs, qe, 2*si+2, arr2);

    findSum(arr1, arr2, countones);
}

// Return sum of elements in range from index qs (quey start)
// to qe (query end).  It mainly uses getSumUtil()
void getSum(int st[][31], int n, int qs, int qe, int countones[31])
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return;
    }
 
    getSumUtil(st, 0, n-1, qs, qe, 0, countones);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int * constructSTUtil(int arr[][31], int ss, int se, int st[][31], int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        copy(begin(arr[ss]), end(arr[ss]), begin(st[si]));
        // st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    int *arr1, *arr2;

    arr1 = constructSTUtil(arr, ss, mid, st, si*2+1);
    arr2 = constructSTUtil(arr, mid+1, se, st, si*2+2);

    int ans[31];
    findSum(arr1, arr2, ans);
    copy(ans, ans+31, begin(st[si]));
    
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
void constructST(int st[][31], int arr[][31], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
}

// function to convert decimal to binary
void decToBinary(int n, int arr[]){
 
    int i = 30;
 
    while (n > 0){
        arr[i] = n % 2;
        n = n / 2;
        i--;
    }
}

int main(){
    
    int q;
    cin >> n >> q;
 
    int arr[n][31] = {0};
 
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        decToBinary(temp, arr[i]);
    }
 
    int l, r;

    int st[4*n][31];
    
    constructST(st, arr, n);

    cout << "Done" << endl;

    for(int i=0; i<q; i++){
        cin >> l >> r;

        int countones[31] = {0};
        int ans = 0;

        getSum(st, n, l, r, countones);

        cout << "Done" << endl;    
        
        for(int j=0; j<31; j++){
            if(countones[j] > (r-l+1)/2) ans += pow(2, 30-j);
        }
 
        cout << ans << endl;
    }
}  