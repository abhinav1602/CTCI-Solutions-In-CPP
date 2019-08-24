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


// returns middle element in linked list
void deleteMiddleElement(Node *head) {
    int len = 0;
    Node *curr = head;

    while(curr!=NULL){
        curr = curr->next;
        len++;
    }
    
    curr = head;

	// middle element is ceiling of len/2
    int target = ceil(len/2);
    // cout<<"L:"<<len<<"T:"<<target<<"\n";
    
    for(int i=1; i<target; i++)
        curr = curr->next;
    
    curr->next = curr->next->next;
    // return curr->data;
}

void printList(Node *head) {
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, x;
        cin>>n;

        // firast element
        cin>>x;
        Node *head = newNode(x);
        Node *curr = head;

        // insert rest of the elements
        for(int i=1; i<=n-1; i++){
            cin>>x;
            Node *temp = newNode(x);
            curr->next = temp;
            curr = curr->next;
        }
		
        deleteMiddleElement(head);
        printList(head);
    }
	return 0;
}
