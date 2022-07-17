#include<bits/stdc++.h>
void prevsmaller(vector<int> &h, vector<int> &left){
    stack<int> st;
    int n = h.size();
    for(int i=0; i<n; i++){
        while(!st.empty()&&h[st.top()]>=h[i]){
            st.pop();
        }
        if(st.empty())
            left[i] = 0;
        else
            left[i] = st.top()+1;
        st.push(i);
    }
}

void nextsmaller(vector<int> &h, vector<int> &right){
    stack<int> st;
    int n = h.size();
    for(int i=n-1; i>=0; i--){
        while(!st.empty()&&h[st.top()]>=h[i]){
            st.pop();
        }
        if(st.empty())
            right[i] = n-1;
        else 
            right[i] = st.top()-1;
        st.push(i);
    }
}

int largestRectangle(vector < int > & heights) {
   // Write your code here.
    int ans = 0;
    int n = heights.size();
    vector<int> left(n), right(n);
    prevsmaller(heights, left);
    nextsmaller(heights, right);
    for(int i=0; i<n; i++){
        ans = max(ans, heights[i]*(right[i]-left[i]+1));
    }
    return ans;
 }