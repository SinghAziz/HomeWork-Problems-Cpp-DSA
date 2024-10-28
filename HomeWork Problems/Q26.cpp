//Linked List

#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;
    Node(int data){
            this -> data=data;
            this -> next=NULL;
    }
};

void insertatHead(Node* &head, int d){
    Node* temp=new Node(d);
    temp-> next = head;
    head = temp;
}

void insertatTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail=temp;
}

void insertatPosition(Node* &tail , Node* & head, int position, int d){
    //Insertion at head
    if ( position == 1 ){
        insertatHead(head, d);
    };

    //Traversing
    Node* temp=head;
    for ( int i=1;i<position-1;i++){
        temp = temp->next;
    }

    //Insertion at last
    if ( temp->next == NULL){
        insertatTail(tail, d);
    }

    //Creation of new node
    Node* nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}

void print(Node* &head){
    if ( head==NULL){
        cout<<"The List is empty";
        return;
    }
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(99);
    Node* head = node1;
    Node* tail = node1; 

    insertatHead(head, 10);
    insertatHead(head, 9 );
    insertatTail(tail, 15);
    insertatPosition(tail, head, 2, 19);
    insertatPosition(tail, head, 4, 94);
    print(head);
}