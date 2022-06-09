#include<bits/stdc++.h>
long f(int *a, int i, int V, vector<vector<long>> &dp){
    if(i == 0)
        return V%a[0] == 0;
    if(dp[i][V] != -1)
        return dp[i][V];
    long take = 0;
    long notTake = f(a, i-1, V, dp);
    if(a[i] <= V)
        take = f(a, i, V-a[i], dp);
    return dp[i][V] = take+notTake;
}

long countWaysToMakeChange(int *a, int n, int V)
{
    //Write your code here
    //vector<vector<long>> dp(n, vector<long>(V+1, -1));
    //return f(a, n-1, V, dp);
    vector<long> prev(V+1, 0), cur(V+1, 0);
    for(int i=0; i<=V; i++) prev[i] = i%a[0]==0;
    for(int i=1; i<n; i++){
        for(int v=0; v<=V; v++){
            long take = 0;
            long notTake = prev[v];
            if(a[i]<=v)
                take = cur[v-a[i]];
            cur[v] = take+notTake;
        }
        prev = cur;
    }
    return prev[V];
}