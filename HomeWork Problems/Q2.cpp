/*
PATTERN
For n=4;
        1
        2 3
        3 4 5
        4 5 6 7

Donot use extra variable to print
*/

#include <iostream>
using namespace std;

int main(){
    int i=1;
    while (i<=4){
        int j=i*2;
            while(i<j){
                cout<<i<<" ";
                i++;
            }
        i=j/2;
        i++;
        cout<<endl;
    }
}