//Dobuly Linked List
#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;
    Node *prev;
    //constructor
    Node(int d){
        this->data=d;
        this->data=d;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        int val = this->data;
        if (next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data: "<<val<<endl;
    }
};

//traverse and printing
void print(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertathead(Node* &tail, Node* &head, int d){
    //empty list
    if ( head == NULL ){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp= new Node(d);
        temp->next = head;
        head->prev = temp;
        head=temp;
    }
}

void insertattail(Node* &tail, Node* &head, int d){
    //empty list
    if (tail==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        // cout<<"Value of temp->next is:"<<temp->next<<endl;
    }
}

void insertatposition(Node* &tail, Node* &head, int d,int position){
    //empty list
    if ( position==1 ){
        insertathead(tail, head, d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    
    while ( cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //inserting at last position
    if ( temp -> next == NULL){
        insertattail(tail, head, d);
        return;
    }

    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;


}
void deleteNode ( int position,Node* &head){
    //deleting first node
    if ( position==1 ){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while ( cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertathead(tail, head, 5);
    insertattail(tail, head ,4);
    insertatposition(tail, head, 6, 3);
    deleteNode(2, head);
    // insertatposition(tail, head, 9, 3);
    // insertatposition(tail, head, 12, 4);
    print(head);
    return 0;
}