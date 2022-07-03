#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    int j=n-1;
    int i=m-1;
    for(int k=m+n-1; k>=0; k--){
        if (i >= 0 && arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } else {

            arr1[k] = arr2[j];
            j--;
        }
    }
    return arr1;
}