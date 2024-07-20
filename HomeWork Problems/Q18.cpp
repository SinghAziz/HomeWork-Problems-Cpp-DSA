/* Problem Statement
AP:3*n+7
Print the value of a(n) when n is being input
*/

#include <iostream>
using namespace std;

int AP(int n){
    return (3*n)+(7);
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<AP(n);
}

