#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // First Phase
    LinkedListNode<int> *iter = head;
    LinkedListNode<int> *front = head;
    while(iter){
        front = iter->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy ->next = front;
        iter = front;
    }
    
    // Second Phase
    iter = head;
    while(iter){
        if(iter->random)
            iter->next->random = iter->random->next;
        else
            iter->next->random = iter->random;
        iter = iter->next->next;
    }
    
    // Third Phase
    iter = head;
    LinkedListNode<int> *copyHead = new LinkedListNode<int> (-1);
    LinkedListNode<int> *copy = copyHead;
    while(iter){
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        iter = iter->next;
        copy = copy->next;
    }
    return copyHead->next;
}
