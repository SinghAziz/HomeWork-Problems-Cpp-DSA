/* Problem Statement
Making all the values in size defined array to 1
*/

#include<iostream>
using namespace std;

int main(){
    int arr[10]={0};
    for (int i=0;i<10;i++){
        arr[i]=1;
        cout<<arr[i]<<" ";
    }
}