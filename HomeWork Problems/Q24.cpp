//Insertion Sort
#include<iostream>
using namespace std;

int main(){
    int arr[6]={1, 3,2,5, 8, 7};

    int temp;
    for (int i=1;i<6;i++){
        temp=arr[i];
        int j=i-1;
        for (;j>0;j--){
            if (arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
   
        }
     arr[j+1]=temp;
    }

    for ( int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}