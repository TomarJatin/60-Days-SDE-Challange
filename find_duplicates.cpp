#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int ans = 0;
    vector<int> count(n, 0);
    for(int i=0; i<n; i++)
        count[arr[i]]++;
    for(int i=0; i<n; i++){
        if(count[i] >= 2){
            ans = i;
            break;
        }
    }
    return ans;
}
