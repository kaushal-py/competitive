#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t;

// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
 
/*  si -> index of current node in segment tree
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(int tree[], int lazy[], int si, int ss, int se, int us,
                     int ue, int diff)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy[si] != 0)
    {
        // Make pending updates using value stored in lazy
        // nodes
        tree[si] += (se-ss+1)*lazy[si];
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
 
        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si] = 0;
    }
 
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
 
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] += (se-ss+1)*diff;
 
        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
    int mid = (ss+se)/2;
    updateRangeUtil(tree, lazy, si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(tree, lazy, si*2+2, mid+1, se, us, ue, diff);
 
    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
 
// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(int tree[], int lazy[], int n, int us, int ue, int diff)
{
   updateRangeUtil(tree, lazy, 0, 0, n-1, us, ue, diff);
}
 
 
/*  A recursive function to get the sum of values in given
    range of the array. The following are parameters for
    this function.
    si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
int getSumUtil(int tree[], int lazy[], int ss, int se, int qs, int qe, int si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        tree[si] += (se-ss+1)*lazy[si];
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
 
        // unset the lazy value for current node as it has
        // been updated
        lazy[si] = 0;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value 
    // (same as it was for query in our previous post)
 
    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];
 
    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se)/2;
    return getSumUtil(tree, lazy, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(tree, lazy, mid+1, se, qs, qe, 2*si+2);
}
 
// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
int getSum(int tree[], int lazy[], int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(tree, lazy, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(int tree[], int lazy[], int arr[], int ss, int se, int si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;
 
    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
 
    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    int mid = (ss + se)/2;
    constructSTUtil(tree, lazy, arr, ss, mid, si*2+1);
    constructSTUtil(tree, lazy, arr, mid+1, se, si*2+2);
 
    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
void constructST(int tree[], int lazy[], int arr[], int n)
{
    // Fill the allocated memory st
    constructSTUtil(tree, lazy, arr, 0, n-1, 0);
}

int main(){
    cin >> t;

    while(t--){
        cin >> n;

        int arr[n];
        ll sum_forv[n];
        ll sum_back[n];

        for(int i=0; i<n; i++) cin >> arr[i];

        sum_forv[0] = 0;
        for(int i=1; i<n-1; i++) sum_forv[i] = sum_forv[i-1] + arr[i];
        sum_forv[n-1] = 0;
        
        sum_back[n-1] = 0;
        for(int i=n-2; i>0; i--) sum_back[i] = sum_back[i+1] + arr[i];
        sum_back[0] = 0;

        ll count_fr[n] = {0};
        ll count_bk[n] = {0};

        for(int i=0; i<n; i++){

            int start = i+1;
            int end = n-1;

            while(start <= end){
                if(start == end){
                    count_fr[i] = start;
                    break;
                }
                if(end - start == 1){
                    if(arr[i] >= sum_forv[end-1] - sum_forv[i]){
                        count_fr[i] = end;                        
                    }
                    else{
                        count_fr[i] = start;
                    }
                    break;
                }
                int mid = (start+end+1)/2;

                if(arr[i] >= sum_forv[mid-1] - sum_forv[i]){
                    start = mid;
                }
                else{
                    end=mid-1;
                }
            }

            start = 0;
            end = i-1;

            while(start <= end){
                if(start == end){
                    count_bk[i] = start;
                    break;
                }
                if(end - start == 1){
                    if(arr[i] >= sum_back[start+1] - sum_back[i]){
                        count_bk[i] = start;
                    }
                    else{
                        count_bk[i] = end;
                    }
                    break;
                }
                int mid = (start+end+1)/2;

                if(arr[i] >= sum_back[mid+1] - sum_back[i]){
                    end = mid;
                }
                else{
                    start=mid+1;
                }
            }

        }

        int ans[n] = {0};

        int tree[4*n] = {0};
        int lazy[4*n] = {0};
        
        constructST(tree, lazy, ans, n);

        for(int k=0; k<n-1; k++){
            updateRange(tree, lazy, n, k+1, count_fr[k], 1);
            // cout << getSum(tree, lazy, n, k, k) << " ";
        }
        for(int k=1; k<n; k++){
            updateRange(tree, lazy, n, count_bk[k], k-1, 1);            
        }

        for(int k=0; k<n; k++){
            cout << getSum(tree, lazy, n, k, k) << " ";
        }
        cout << endl;
    }
}