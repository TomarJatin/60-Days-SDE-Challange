bool solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0)
        return true;
    if(i == 0)
        return arr[0] == target;
    if(dp[i][target] != -1)
        return dp[i][target];
    bool notTake = solve(i-1, target, arr, dp);
    bool take=false;
    if(arr[i] <= target)
        take = solve(i-1, target-arr[i], arr, dp);
    return dp[i][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    //vector<vector<int>> dp(n, vector<int>(k+1, -1));
    //return solve(n-1, k, arr, dp);
    vector<int> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    if(arr[0] <= k)
        prev[arr[0]] = true;
    for(int i=1; i<n; i++){
        for(int target=1; target<=k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[i]<=target)
                take = prev[target-arr[i]];
            curr[target] = take | notTake;
        }
        prev = curr;
    }
    return prev[k];
}