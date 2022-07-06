#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.length();
    unordered_set<int> set;
    int l=0, ans=0;
    for(int r=0; r<n; r++){
        if(set.find(input[r]) != set.end()){
            while(l<r && set.find(input[r]) != set.end()){
                set.erase(input[l]);
                l++;
            }
        }
        set.insert(input[r]);
        ans = max(ans, (r-l+1));
    }
    return ans;
}