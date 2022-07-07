#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* head = new Node<int>(-1);
    Node<int>* temp = head;
    while(first && second){
        if(first->data < second->data){
            temp->next = first;
            temp = first;
            first = first->next;
        }
        else{
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }
    if(first)
        temp->next = first;
    if(second)
        temp->next = second;
    return head->next;
}
