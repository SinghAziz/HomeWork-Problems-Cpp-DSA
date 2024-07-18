/* Problem Statement
Negative Decimal to Binary
*/

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Input the number: ";
    cin>>n;

    //storing
    int n1=0,i=0;
    n=(-n);
    while (n){
        // cout<<"n1 before increment: "<<n1<<endl;
        n1=((~n&1)*pow(10,i))+n1;
        // cout<<"n1 after increment: "<<n1<<endl;
        n=n>>1;
        i++;
    }
    cout<<"n1: "<<n1<<endl;
    n1&=1;
    cout<<"Negative Decimal as Binary is stored as: "<<n1<<endl;
    
    //printing
    //1s compliment
    i=0;
    int n2=0;
    while (n1){
        // cout<<"n1 before increment: "<<n1<<endl;
        n2=((~n1&1)*pow(10,i))+n2;
        // cout<<"n1 after increment: "<<n1<<endl;
        n1=n1>>1;
        i++;
    }
    //2s compliment
    int n3=0;
    i=0;
    n2&=1;
    while (n2){
        n3=n3+(n2&1)*pow(2,i);
        i++;
        n2=n2>>1;
    }
    cout<<"Printing: "<<n3<<endl;
}