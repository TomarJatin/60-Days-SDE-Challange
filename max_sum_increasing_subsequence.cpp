int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<int> dp(n+1, 0);
    int maxSum = 0;
    
    for(int i=0; i<n; ++i){
        dp[i] = rack[i];
        for(int j=0; j<i; ++j){
            if(rack[j] < rack[i]){
               dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}