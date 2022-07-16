#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> next(n);
    stack<int> st;
    st.push(INT_MAX);
    for(int i=n-1; i>=0; i--){
        while(st.top()<=arr[i])
            st.pop();
        if(st.top() == INT_MAX)
            next[i] = -1;
        else
            next[i] = st.top();
        st.push(arr[i]);
    }
    return next;
}