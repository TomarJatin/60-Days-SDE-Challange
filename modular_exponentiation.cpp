#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int ans = 1;
    while(n>0){
        if(n%2)
            ans = (1LL*ans*x)%m;
        x=(1LL*x*x)%m;
        n /= 2;
    }
    return ans;
}