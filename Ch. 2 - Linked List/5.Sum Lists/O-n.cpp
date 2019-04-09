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

void printReverse(Node *head){
    if(head==NULL){
        return;
    }
    printReverse(head->next);
    cout<<head->data;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n, x;
        cin>>n;

        // first element
        cin>>x;
        Node *head1 = newNode(x);
        Node *curr = head1;

        // insert rest of the elements
        for(int i=1; i<=n-1; i++) {
            cin>>x;
            Node *temp = newNode(x);
            curr->next = temp;
            curr = curr->next;
        }

        // size for second list
        cin>>n;
        cin>>x;
        Node *head2 = newNode(x);
        curr = head2;

        // insert rest of the elements
        for(int i=1; i<=n-1; i++) {
            cin>>x;
            Node *temp = newNode(x);
            curr->next = temp;
            curr = curr->next;
        }

        // printList(head1);
        // printList(head2);

        int carry = 0, digit, sum;

        Node *ans = newNode(0);
        Node *ansHead = ans;

        while(head1!=NULL && head2!=NULL){  
            sum = ((head1->data)+(head2->data)+carry);
            digit = sum%10;
            carry = sum/10;
            // cout<<"sum:"<<sum<<"\n";
            ans->data = digit;

            if(head1->next!=NULL && head2->next!=NULL || carry > 0){
                ans->next = newNode(0);
                ans = ans->next;    
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }

        if(sum/10 > 0)
            ans->data = carry;

        // printList(ansHead);
        printReverse(ansHead);
        cout<<"\n";
	}
	return 0;
}