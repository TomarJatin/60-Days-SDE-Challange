#include<bits/stdc++.h>
bool isPalindrom(int i, int j, string &s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;
    for(int i=n-1; i>=0; i--){
        int mini = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrom(i, j, str)){
                int cost = 1+dp[j+1];
                mini = min(cost, mini);
            }
        }
        dp[i]=mini;
    }
    return dp[0]-1;
}