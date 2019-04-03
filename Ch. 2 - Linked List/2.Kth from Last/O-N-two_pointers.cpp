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


// returns kth element from the last
int KthlastElement(Node *head, int k){
    int len = 0;
    Node *curr = head;

    while(curr!=NULL && k>0){
        curr = curr->next;
        k--;
    }   
    
    if(k>0)
        return -1;
    
    while(curr!=NULL){
        curr = curr->next;
        head = head->next;
    }
    return head->data;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, x, k;
        cin>>n>>k;

        // first element
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
		
        int kth_last_element = KthlastElement(head, k);
        cout<<kth_last_element<<"\n";
    }
	return 0;
}
