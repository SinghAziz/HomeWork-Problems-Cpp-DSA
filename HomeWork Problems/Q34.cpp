//Binary Search Tree
#include<iostream>
#include <bits/stdc++.h>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node (int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node *root, int data){
    if (root==NULL){
        root=new Node(data);
        return root;
    }

    if(data>root->data){
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left=insertIntoBST(root->left,data);
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cin>>data;

    while (data!=-1){
        root=insertIntoBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    if (root==NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty()){
        Node* frontNode=Q.front();
        Q.pop();
        if (frontNode==NULL){
            cout<<endl;
        
        if (!Q.empty()){
            Q.push(NULL);
        }
        }
        else{
            cout<<frontNode->data<<" ";
            if (frontNode->left){
                Q.push(frontNode->left);
            }
            if (frontNode->right){
                Q.push(frontNode->right);
            }
        }
    }

}

void inordertraversal(Node *root){
    if (root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
void preordertraversal(Node *root){
    if ( root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(Node *root){
    if (root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
    
}

int main(){
    Node *root =NULL;
    cout<<"Enter data to create BST:";
    takeinput(root);

    cout<<endl<<"Level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"Inorder traversal:"<<endl;
    inordertraversal(root);

    cout<<endl<<"Pre order traversal: "<<endl;
    preordertraversal(root);

    cout<<endl<<"Post order traversal: "<<endl;
    postordertraversal(root);

    return 0;
}
