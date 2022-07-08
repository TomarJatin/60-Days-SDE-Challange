#include <bits/stdc++.h> 
/****************************************************************
 
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

*****************************************************************/
int getdiff(Node* h1, Node* h2){
    int l1=0;
    int l2=0;
    while(h1 || h2){
        if(h1){
            l1++;
            h1=h1->next;
        }
        if(h2){
            l2++;
            h2=h2->next;
        }
    }
    return l1-l2;
}

int findIntersection(Node *firstHead, Node *secondHead)
{
    int diff = getdiff(firstHead, secondHead);
    if(diff< 0)
        while(diff++ != 0) secondHead=secondHead->next;
    else while(diff-- != 0) firstHead=firstHead->next;
    while(firstHead){
        if(firstHead == secondHead)
            return firstHead->data;
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }
    return -1;
}