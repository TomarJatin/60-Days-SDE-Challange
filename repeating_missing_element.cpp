#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> count(n, 0);
    pair<int, int> ans;
    for(int i=0; i<n; i++)
        count[arr[i]-1]++;
    for(int i=0; i<n; i++){
        if(count[i]==0)
            ans.first = i+1;
        if(count[i]>1)
            ans.second = i+1;
    }
    return ans;
}
