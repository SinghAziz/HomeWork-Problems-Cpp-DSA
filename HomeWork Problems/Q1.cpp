/*
PATTERN
For n=4;
        4 3 2 1
        4 3 2 1
        4 3 2 1
        4 3 2 1
*/

#include <iostream>
using namespace std;

int main(){
    int i=1,j=4;
    while (i<=4){
        j=4;
        while (j>0){
            cout <<j<<" ";
            j--;
        }
        cout<<endl;
        i++;
    }
}