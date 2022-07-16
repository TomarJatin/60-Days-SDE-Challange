// Stack class.
class Stack {
    int arr[10000];
    int t;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
        t = -1;
    }

    void push(int num) {
        // Write your code here.
        if(t>=size)
            return;
        t++;
        arr[t] = num;
    }

    int pop() {
        // Write your code here.
        if(t != -1)
            return arr[t--];
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(t != -1 && t<size)
            return arr[t];
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(t == -1)
            return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(t>=size)
            return 1;
        return 0;
    }
    
};