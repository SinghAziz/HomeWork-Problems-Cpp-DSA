#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if (this->next != NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data: "<<value<<endl;
    }
    
};

void insertnode(Node*&tail, int element, int d){

    //empty list
    if (tail == NULL){
        Node* newNode= new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        //non empty list
        Node* curr=tail;
        while (curr->data != element){
            curr=curr->next;
        }

        //element is found, curr representing element wala node
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(Node* &tail){
    Node* temp=tail;
    
    //empty list
    if (tail==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    
    do {
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){

    //empty list
    if ( tail == NULL){
        cout<<"The list is empty, please check again"<<endl;
        return;
    }
    else{
        //non empty

        //assuming that "value" is present in the linked list 
        Node* prev=tail;
        Node* curr= prev->next;

        while(curr->data != value){
            prev=curr;
            curr=curr->next;
        }
        prev->next = curr->next;

        // if only 1 element is present
        if (curr==prev){
            tail=NULL;
        }
        //>=2 Node linked list
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* tail=NULL;
    insertnode(tail, 4,2 );
    insertnode(tail, 2,5 );
    print(tail);
    return 0;
}