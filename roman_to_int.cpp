#include<bits/stdc++.h>
int romanToInt(string s) {
    int n = s.size();
    unordered_map<char, int> mp =
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};
    int ans = 0;
    int prev = 0;
    for(int i=n-1; i>=0; i--){
        char ch = s[i];
        int cur = mp[ch];
        if(cur>=prev)
            ans+=cur;
        else
            ans-=cur;
        prev = cur;
    }
    return ans;
}