#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int ans = 0;
    sort(arr.begin(), arr.end());
    int count = 1, prev = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] == prev+1)
            count++;
        else if(arr[i] != prev)
            count = 1;
        prev = arr[i];
        ans = max(ans, count);
    }
    return ans;
}