class Queue {
public:
    int f;
    int rear;
    int *arr;
    int size;
    
    Queue() {
        // Implement the Constructor
        size = 5000;
        arr = new int[size];
        f = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear == f)
            return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear == f)
            return -1;
        int x = arr[f];
        f++;
        return x;
    }

    int front() {
        // Implement the front() function
        if(f == rear){
            return -1;
        }
        return arr[f];
    }
};