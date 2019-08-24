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

int findIntersectingNode(Node* head1, Node* head2) {
    int l1=0, l2=0;
    Node *temp1 = head1, *temp2 = head2;

    // first calculate length of both
    while(temp1 != NULL){
        temp1 = temp1->next;
        l1++;
    }

    while(temp2 != NULL){
        temp2 = temp2->next;
        l2++;
    }

    // now find the difference in length for adding extra overhead to the longer list
    temp1 = head1, temp2 = head2;
    int diff = abs(l1-l2), cd = 0;

    if(l1 > l2){
        while(cd!=diff){
            temp1 = temp1->next;
            cd++;
        }
    }
    else if(l1 < l2){
        while(cd!=diff){
            temp2 = temp2->next;
            cd++;
        }
    }

    // after giving the longer list a lead of cd nodes move both pointers until they meet at common point
    while(temp1 != temp2 && temp1 != NULL && temp2 != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    //this common point is the point of intersection of both list, return its data
    return temp1->data;
}

int main(){
	/*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
	
    int ans = findIntersectingNode(head1, head2);
    cout<<ans<<"\n";
	return 0;
}