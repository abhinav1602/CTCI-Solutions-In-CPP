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

int detectloop(Node *head)
{
   // your code here
   Node *p1 = head, *p2 = head;
   
   while(p2!=NULL && p2->next!=NULL){
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1==p2)
            return 1;
   }
    return 0;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n, x;
        cin>>n;

        // first element
        cin>>x;
        Node *head = newNode(x);
        Node *curr = head;
        Node *temp;

        // insert rest of the elements
        for(int i=1; i<=n-1; i++) {
            cin>>x;
            temp = newNode(x);
            curr->next = temp;
            curr = curr->next;
        }

        /* Create a loop for testing */
        int c;
        cin>>c;
        if(c>0){
            c=c-1;
            temp=head;
            // move to the loop start location for assigning it to the next address of last node
            while(c--)
                temp=temp->next;
            curr->next=temp;
        }

        int ans = detectloop(head);
        cout<<(ans?"LOOP Present":"No LOOP Detected");
        // printList(ansHead);
        cout<<"\n";
	}
	return 0;
}