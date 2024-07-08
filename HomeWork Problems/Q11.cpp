/* Problem Statement

1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1

for n=5
*/

#include<iostream>
using namespace std;

int main(){
    int i=1;
    while (i<=5){
        int j=1;
        //First Triangle
        while (j<=5-i+1){
            cout<<j<<" ";
            j++;
        }
        //Second Triangle
        j=5-i+1;
        while (j<5){
            cout<<"* ";
            j++;
        }
        //Third Triangle
        j=5-i+1;
        while(j< 5){
            cout<<"* ";
            j++;
        }
        //Fourth Triangle
        j=5-i+1;
        while (j>0){
            cout<<j<<" ";
            j--;
        }
        cout<<endl;
        i++;
    }
}