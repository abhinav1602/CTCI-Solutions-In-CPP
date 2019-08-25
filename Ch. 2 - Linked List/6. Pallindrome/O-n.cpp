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

 bool isPalindrome(Node* head) {
    Node *slow = head, *fast = head;        
    stack<int> s;
    
    if (slow==NULL)
        return true;
    
    s.push(slow->data);
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        s.push(slow->data);
    }
    
    if(!fast)
        s.pop();
            
    while(slow!=NULL && !s.empty()) {
        // cout << " Comparing: " << s.top() << " and " << slow->data <<"\n";
        if(!s.empty() && s.top() != slow->data)
            return false;
        
        s.pop();
        slow = slow->next;
    }
    return true;
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

        // insert rest of the elements
        for(int i=1; i<=n-1; i++){
            cin>>x;
            Node *temp = newNode(x);
            curr->next = temp;
            curr = curr->next;
        }
		
        int is_pallindrome = isPallindrome(head);
        cout<<(is_pallindrome?"This is a Pallindrome":"Not a Pallindrome")<<"\n";
    }
	return 0;
}
 