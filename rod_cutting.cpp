int f(int i, int l, vector<int> &price, vector<vector<int>> dp){
    if(i==0) return l*price[0];
    if(dp[i][l] != -1)
        return dp[i][l];
    int take = 0;
    int notTake = f(i-1, l, price, dp);
    int rodlength = i+1;
    if(rodlength<=l)
        take = price[i]+f(i, l-rodlength, price, dp);
    return dp[i][l] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    //vector<vector<int>> dp(n, vector<int>(n+1, -1));
    //return f(n-1, n, price, dp);
    vector<int> prev(n+1, 0);
    for(int i=0; i<=n; i++) prev[i]=i*price[0];
    for(int i=1; i<n; i++){
        for(int l=0; l<=n; l++){
            int take = 0;
            int notTake = prev[l];
            int rodlength = i+1;
            if(rodlength<=l)
                take = price[i]+prev[l-rodlength];
            prev[l] = max(take, notTake);
        }
    }
    return prev[n];
}
