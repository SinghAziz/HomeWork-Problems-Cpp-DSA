#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    //Initialize your data structure.
    CircularQueue(int n){
        size=n;
        arr=new int[n];
        front=rear=-1;
    }
    //Enqueues 'x' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //to check whether queue is full. 
        if ((front==0 && rear==size-1)||(rear==(front-1)%(rear-1))){
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    int dequeue(){
        if (front==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if (front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};

int main(){
    CircularQueue C(5);
    C.enqueue(5);
    C.enqueue(6);
    C.enqueue(7);
    cout<<C.dequeue();
    cout<<C.dequeue();
    return 0;
}