/* Problem Statement
Reverse Integer
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"INPUT: ";
    cin>>n;
    int n1=0;
    while (n){
        n1+=(n%10);
        n/=10;
        n1*=10;
    }
    cout<<n1/10;
}