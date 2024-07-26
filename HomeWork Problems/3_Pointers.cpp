/* Problem Statement
Sorting 0,1,2 in order using 3 pointers
*/

#include<iostream>
using namespace std;

int main(){

    int arr[5]={1,0,1,2,1};
    int i=0,j=5,k=5;

    while (i<j){
        while (arr[i]==0){
            i++;
        }
        while(arr[j]==1){
            j--;
        }
        if (i<j){
            swap(arr[i],arr[j]);
        }
        i++;
        j--;
    }

    i=0;
    while (i<k){
        while (arr[i]!=2){
            i++;
        }
        while (arr[k]!=2){
            k--;
        }
        k++;
        if (i<k){
        swap(arr[i],arr[k]);
        }
        i++;
        k=4;
    for (int m=0;m<5;m++){
        cout<<arr[m]<<" ";
    }
    cout<<endl;
    }

    cout<<endl<<"Final"<<endl;
    for (int m=0;m<5;m++){
        cout<<arr[m]<<" ";
    }
}

