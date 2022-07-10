#include<bits/stdc++.h>
void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int target, int ind){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    for(int i=ind; i<arr.size(); i++){
        if(i>ind && arr[i] == arr[i-1]) continue;
        if(arr[i]>target) break;
        temp.push_back(arr[i]);
        solve(arr, ans, temp, target-arr[i], i+1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
    vector<int> temp;
    solve(arr, ans, temp, target, 0);
    return ans;
}
