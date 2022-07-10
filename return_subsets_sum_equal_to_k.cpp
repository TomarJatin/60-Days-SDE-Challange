void solve(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int ind, int k){
    if(ind == arr.size()){
        if(k==0)
            ans.push_back(temp);
        return;
    }
        temp.push_back(arr[ind]);
        solve(arr, temp, ans, ind+1, k-arr[ind]);
        temp.pop_back();
    solve(arr, temp, ans, ind+1, k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> temp;
    vector<vector<int>> ans;
    solve(arr, temp, ans, 0, k);
    return ans;
}