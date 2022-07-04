#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int ans = 1;
    long long xx = x;
    xx = xx%m;
    if(xx == 0) return 0;
    while(n>0){
        if(n%2){
            ans=(ans*xx)%m;
            n=n-1;
        }
        else{
            xx = (xx*xx)%m;
            n=n/2;
        }
    }
    return ans;
}