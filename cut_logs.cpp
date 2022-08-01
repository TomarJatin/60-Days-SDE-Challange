#include<bits/stdc++.h>

int dp[101][10001];
int func(int K , int N)
{
    if(N==1 || N==0)
    {
        return N;
    }

    if(K==1)
    {
        // if only one axe is left , then in worst u have to cut every log
        return N;
    }

    if(dp[K][N]!=-1)
   {
       return dp[K][N];
   }

   int ans=INT_MAX ; // minimum no of trials needed (till having K axes , N Logs)
   // finding the critical no of Logs

   int low=1;
   int high=N;

   while(low<=high)
   {
       int mid = (low + (high-low)/2);

       int go_below=func(K-1 , mid-1);// axe break at mid  , no of logs left is mid-1
       int go_above=func(K , N-mid);// axe not break , no of logs left is N-mid

       // as we dont know axe will break or not

       // what we will do is we take the max no of trials from broken or not broken


       int temp = 1+max(go_above,go_below);

       if(go_above>go_below)
       {
           low=mid+1;
       }
       else
       {
           high=mid-1;
       }

       ans = min(ans , temp);
   }

   return dp[K][N]=ans;


}


int cutLogs(int k, int n)
{
    memset(dp , -1 , sizeof(dp));
    return func(k,n);
}