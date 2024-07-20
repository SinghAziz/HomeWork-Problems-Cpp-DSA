/* Problem Statement
Total number of set bits in the 2 numbers entered i.e. number of bits having value 1
*/

#include <iostream>
using namespace std;

int setbit(int a, int b){
    int count=0;
    while(a){
        if (a&1){
            count++;
        }
        a=a>>1;
    }
    while (b){
        if (b&1){
            count++;
        }
        b=b>>1;
    }
    return count;
}

int main(){
    int a,b;
    cout<<"Enter the values: ";
    cin>>a>>b;
    cout<<setbit(a,b);
}