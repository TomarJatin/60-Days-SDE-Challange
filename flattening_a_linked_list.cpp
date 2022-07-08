#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node *merge(Node *first, Node *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    Node *merged = NULL;

    if (first->data < second->data){
        merged = first;
        merged->child = merge(first->child, second);
    }
    else{
        merged = second;
        merged->child = merge(first, second->child);
    }
    merged->next = nullptr;
    return merged;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    head->next = flattenLinkedList(head->next);

    head = merge(head, head->next);

    return head;
}
