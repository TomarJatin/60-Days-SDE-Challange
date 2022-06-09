#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j] == s){
                vector<int> a;
                a.push_back(min(arr[i], arr[j]));
                a.push_back(max(arr[i], arr[j]));
                ans.push_back(a);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}