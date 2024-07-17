/* Problem Statement
Count number of 1 bits
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Input: ";
    cin>>n;
    int count=0;
    while (n){
        if (n&1){
            count++;
        }
        n=n>>1;
    }
    cout<<count;
}