#include<bits/stdc++.h>
using namespace std;
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

struct Node * segregateEvenOdd(struct Node **head_ref) 
{
	Node *evenStart = NULL; 
 
	Node *evenEnd = NULL; 

	Node *oddStart = NULL; 

	Node *oddEnd = NULL; 
 
	Node *currNode = *head_ref; 
	
	while(currNode != NULL)
	{ 
		int val = currNode -> data; 

		if(val % 2 == 0) 
		{ 
			if(evenStart == NULL)
			{ 
				evenStart = currNode; 
				evenEnd = evenStart; 
			} 
			
			else
			{ 
				evenEnd -> next = currNode; 
				evenEnd = evenEnd -> next; 
			} 
		} 

		else{ 
			if(oddStart == NULL)
			{ 
				oddStart = currNode; 
				oddEnd = oddStart; 
			} 
			else
			{ 
				oddEnd -> next = currNode; 
				oddEnd = oddEnd -> next; 
			} 
		} 

		currNode = currNode -> next;	 
	} 
	
	if(oddStart == NULL && evenStart != NULL)
	{ 
		return evenStart; 
	} 
	else if(oddStart != NULL && evenStart == NULL)
	{ 
		return oddStart; 
	} 
	
	evenEnd -> next = oddStart; 
	oddEnd -> next = NULL; 
return evenStart;
} 


void push(Node** head_ref, int new_data)   
{   
    
    Node* new_node = new Node();  
    Node *last = *head_ref;  
    new_node->data = new_data;   
    new_node->next = NULL;   
    if (*head_ref == NULL)   
    {   
        *head_ref = new_node;   
        return;   
    }   
    while (last->next != NULL)   
        last = last->next;   
    last->next = new_node;   
    return;   
}   

void printList(struct Node *node) 
{ 
	while (node!=NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
	} 
} 


int main() 
{ 
    int p;
    cin>>p;
    while(p--)
    {
    struct Node* head = NULL; 
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        push(&head,x);
    }
    struct Node *final=	segregateEvenOdd(&head); 
	printList(final); 
	cout<<endl;

    }


	return 0; 
} 

