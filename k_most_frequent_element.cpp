#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
   // Write your code here.
 
   unordered_map<int, int> mp;
   for(auto i: arr)
       mp[i]++;
   
   priority_queue<pair<int,int>> pq;
   for(auto it: mp)
   {
       pq.push({it.second, it.first});
       
   }
   vector<int> ans;
   while(k--)
   {
       ans.push_back(pq.top().second);
       pq.pop();
   }
   sort(ans.begin(), ans.end());
   return ans;
   
}