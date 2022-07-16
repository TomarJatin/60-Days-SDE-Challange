#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> st, extra;
    
    public:

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!st.empty()){
            extra.push(st.top());
            st.pop();
        }
        st.push(val);
        while(!extra.empty()){
            st.push(extra.top());
            extra.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st.empty())
            return -1;
        int x = st.top();
        st.pop();
        return x;
    }

    int peek() {
        // Implement the peek() function here.
        if(st.empty())
            return -1;
        return st.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st.empty();
    }
};