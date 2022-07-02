#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    int idx1, idx2;
    for(idx1=n-2; idx1>=0; idx1--){
        if(p[idx1]<p[idx1+1])
            break;
    }
    if(idx1<0)
        reverse(p.begin(), p.end());
    else{
        for(idx2=n-1; idx2>idx1; idx2--){
            if(p[idx1]<p[idx2])
                break;
        }
        swap(p[idx1], p[idx2]);
        reverse(p.begin()+idx1+1, p.end());
    }
    return p;
}