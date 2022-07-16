void insert(stack<int> &st, int ele){
    if(st.empty() || ele>=st.top()){
        st.push(ele);
        return;
    }
    int e = st.top();
    st.pop();
    insert(st, ele);
    st.push(e);
}

void sortStack(stack<int> &stack)
{
    if(stack.size() == 1)
        return;
    int ele = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, ele);
}