#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    if(n == 0)
        return 0;
    vector<int> temp;
    int len = 1;
    temp.push_back(arr[0]);
    for(int i=1; i<n; i++){
        auto b = temp.begin(), e = temp.end();
        auto it = lower_bound(b, e, arr[i]);
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            *it = arr[i];
        }     
    }
    return len;
}
