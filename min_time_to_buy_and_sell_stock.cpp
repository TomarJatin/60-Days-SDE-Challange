#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int ans = 0, n = prices.size();
    int min_buy = prices[0];
    for(int i=1; i<n; i++){
        int profit = prices[i] - min_buy;
        min_buy = min(min_buy, prices[i]);
        ans = max(ans, profit);
    }
    return ans;
}