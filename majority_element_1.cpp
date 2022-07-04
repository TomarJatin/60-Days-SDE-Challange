#include <bits/stdc++.h> 
bool isMajority(int arr[], int candidate, int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == candidate)
            count++;
    }
    if(count > n/2)
        return true;
    return false;
}
int findcandidate(int arr[], int n){
    int count = 0;
    int candidate = 0;
    for(int i=0; i<n; i++){
        if(count == 0)
            candidate = arr[i];
        if(arr[i]==candidate) count++;
        else count--;
    }
    return candidate;
}
int findMajorityElement(int arr[], int n) {
    int candidate = findcandidate(arr, n);
    if(isMajority(arr, candidate, n))
        return candidate;
    else
        return -1;
}