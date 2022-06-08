int f(vector<int> &val, vector<int> &wt, int i, int W, vector<vector<int>> dp){
    if(i==0){
        if(wt[0]<=W)
            return val[0];
        else
            return 0;
    }
    if(dp[i][W] != -1)
        return dp[i][W];
    int notTake = f(val, wt, i-1, W, dp);
    int Take = 0;
    if(wt[i]<=W)
        Take = val[i]+f(val, wt, i-1, W-wt[i], dp);
    return dp[i][W] = max(Take, notTake);
}

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
	// Write your code here
    //vector<vector<int>> dp(n, vector<int>(w+1, -1));
    //return f(val, wt, n-1, w, dp);
    vector<int> prev(W+1, 0);
    for(int i=wt[0]; i<=W; i++)
        prev[i]=val[0];
    for(int i=1; i<n; i++){
        for(int w=W; w>=0; w--){
            int notTake = prev[w];
            int take = 0;
            if(wt[i]<=w)
                take = val[i]+prev[w - wt[i]];
            prev[w] = max(take, notTake);
        }
    }
    return prev[W];
}