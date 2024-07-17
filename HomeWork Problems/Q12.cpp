/* Problem Statement
Subtract the product and sum of the digits of an integer
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Input the Value: ";
    cin>>n;
    int sum=0, product=1;
    while (n>0){
        sum+=(n%10);
        product*=(n%10);
        n/=10;
    }
    cout<<"Sum: "<<sum<<endl;
    cout<<"Product: "<<product<<endl;
}