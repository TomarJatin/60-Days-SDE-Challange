#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
    if(head == NULL || head->next == NULL || k==0)
        return head;
    int length = 1;
    Node* temp = head;
    while(temp->next != NULL){
        length++;
        temp=temp->next;
    }
    temp->next = head;
    k = k%length;
    int end = length - k;
    while(end--) temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}