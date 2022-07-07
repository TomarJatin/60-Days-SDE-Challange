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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    int carry = 0;
    Node* res = new Node(-1);
    Node* temp = res;
    while((head1 || head2) || carry){
        int sum =0;
        if(head1){
            sum+=head1->data;
            head1 = head1->next;
        }
        if(head2){
            sum+=head2->data;
            head2 = head2->next;
        }
        sum+=carry;
        carry = sum/10;
        sum=sum%10;
        Node* node = new Node(sum);
        temp->next = node;
        temp = temp->next;
    }
    return res->next;
}