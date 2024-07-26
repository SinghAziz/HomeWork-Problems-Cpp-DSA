/* Problem Statement
Sorting 0,1,2 in order using 3 pointers
*/

#include<iostream>
using namespace std;

int main(){
    cout<<"Hello";
    int arr[5]={1,0,1,0,1};
    int i=0,j=5;

    while (i<j){
        while (arr[i]==0){
            i++;
        }
        while(arr[j]==1){
            j--;
        }
        while (i<j){
            swap(arr[i],arr[j]);
        }

        i++;
        j--;
    }
    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}