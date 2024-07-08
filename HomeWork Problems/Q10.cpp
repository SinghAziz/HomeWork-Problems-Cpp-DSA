/* Problem Statement
      1
    2 2
  3 3 3 
4 4 4 4

for n=4
*/

#include<iostream>
using namespace std;

int main(){
    int i=1;
    while (i<=4){
        int j=i;
        while(j<4){
            cout<<"  ";
            j++;
        }
        j=4-i+1;
        while (j<=4){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}