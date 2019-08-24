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

void removeDuplicates(struct Node *head){
	unordered_set<int> us;
	struct Node *curr = head, *prev = NULL;
	
	while(curr!=NULL && curr->next!=NULL){
		if(us.find(curr->data) != us.end()){
			prev->next = curr->next;
			delete(curr);
		}
		else{
			us.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
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

	// printList(head);
	removeDuplicates(head);

	cout<<"\n";
	printList(head);

	return 0;
}