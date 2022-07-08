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

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(head == NULL || head->next == NULL)
        return NULL;
    Node* fast = head;
    Node* slow = head;
    Node* start = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            while(slow != start){
                slow=slow->next;
                start=start->next;
            }
            return slow;
        }
    }
    return NULL;
}