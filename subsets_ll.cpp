#include<bits/stdc++.h>
void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int ind){
    ans.push_back(temp);
    for(int i=ind; i<arr.size(); i++){
        if(i!=ind && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(arr, ans, temp, i+1);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    solve(arr, ans, temp, 0);
    return ans;
}