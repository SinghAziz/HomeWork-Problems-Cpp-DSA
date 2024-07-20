/* Problem Statement
Fibonacci Series
Input:n
Output: The nth value of the series 
*/

#include<iostream>
using namespace std;

int Fib(int n){
    int a=0,b=1,out=0;
    for (int i=0;i<n-2;i++){
        out=a+b;
        a=b;
        b=out;
    }
    return out;
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<Fib(n);
}