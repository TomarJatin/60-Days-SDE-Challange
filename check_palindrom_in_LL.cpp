#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverse(LinkedListNode<int> *head){
    if(head == NULL || head->next == NULL) return head;
    LinkedListNode<int> * newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next == NULL) return true;
    LinkedListNode<int>* fast = head;
    LinkedListNode<int>* middle = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        middle = middle->next;
    }
    middle->next = reverse(middle->next);
    LinkedListNode<int>* temp = middle->next;
    LinkedListNode<int>* start = head;
    while(temp){
        if(temp->data != start->data)
            return false;
        temp=temp->next;
        start=start->next;
    }
    middle->next = reverse(middle->next);
    return true;
}