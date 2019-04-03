#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node * next;
};


struct Node *newNode(int data){
	Node *n = new Node;
	n->data = data;
	n->next = NULL;
	return n;
}


void printList(struct Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}


// using two pointers to check if any no. is repeated
void removeDuplicates(struct Node *head){
	struct Node *outer = head, *delNode;
	struct Node *inner;

	while(outer!=NULL && outer->next!=NULL){
		inner = outer;
		while(inner->next!=NULL){
			//if no. is repeated remove the connection
			if(outer->data == inner->next->data){
				delNode = inner->next;
				inner->next = delNode->next;
				delete(delNode);
			}
			else
				inner = inner->next;
		}			
		outer = outer->next;
	}

}


int main(){
	int n, x;
	cin>>n;

	cin>>x;

	Node *head = newNode(x);
	Node *curr = head;

	for(int i=1; i<=n-1; i++){
		cin>>x;
		struct Node *nxt = newNode(x);
		curr->next = nxt;
		curr = curr->next;
	}

	printList(head);
	removeDuplicates(head);

	cout<<"\n";
	printList(head);

	return 0;
}