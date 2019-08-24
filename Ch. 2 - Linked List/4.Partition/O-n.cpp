#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node *newNode(int data){
    Node *n = new Node();
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(Node *head) {
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}


/*
	This metthod check for value in the next node:
	 	if it is less than the partition value it is moved before the head
	 	if it is greater than the partion value we move to the next node
*/
Node *partition(Node *head, int p){
	Node *curr = head, *last=head, *temp;
	
	while(curr!=NULL && curr->next!=NULL){
		// cout<<":"<<curr->data<<"\n";
		if(curr->next->data < p){
			temp = curr->next;
			curr->next = curr->next->next;
			temp->next = head;
			head = temp;
		}
		// before moving to the next node, we must check if its value is greater than(or equal) the patition value
		if(curr->next!= NULL && curr->next->data >= p)
			curr = curr->next;
	}
	return head;
}


int main(){
	int t;
	cin>>t;

	while(t--){
		int n, p, x;
        cin>>n>>p;

        // first element
        cin>>x;
        Node *head = newNode(x);
        Node *curr = head;

        // insert rest of the elements
        for(int i=1; i<=n-1; i++) {
            cin>>x;
            Node *temp = newNode(x);
            curr->next = temp;
            curr = curr->next;
        }
        head = partition(head, p);
        printList(head);
	}
	return 0;
}