/* Problem Statement
Sum of all numbers in array
*/

#include<iostream>
using namespace std;

int main(){
    int arr[10]={1,3,24,32,13,34,231,21,32,4};
    int sum=0;
    for (int i=0;i<10;i++){
        sum+=arr[i];
    }
    cout<<sum;
}
