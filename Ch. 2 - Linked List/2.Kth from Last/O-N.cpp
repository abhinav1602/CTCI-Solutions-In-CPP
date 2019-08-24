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

    while(curr!=NULL){
        curr = curr->next;
        len++;
    }
    
    curr = head;
    if(k>len)
        return -1;

    // kth element from the end is len-k element from the last 
    int target = (len-k)+1;
    
    for(int i=1; i<target; i++)
        curr = curr->next;
    
    return curr->data;    
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
