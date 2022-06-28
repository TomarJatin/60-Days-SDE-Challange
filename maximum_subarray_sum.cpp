#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans =0;
    long long sum =0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>ans)
            ans = sum;
        if(sum<0)
            sum=0;
    }
    return ans;
}