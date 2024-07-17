/* Problem Statement
Complement of Base 10
flip 1 to 0 vis-a-vis
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"INPUT: ";
    cin>>n;
    int i,j=0;
    while (n){
        i=n%10;
        if (i==1){
            j=j+0;
            j*=10;
            n=n>>1;
        }
        else{
            j+=1;
            j*=10;
            n=n>>1;
        }
    }
    cout<<j/10;
}