/* Problem Statement
1 1 1 1
  2 2 2
    3 3
      4

for n=4 
*/

#include<iostream>
using namespace std;

int main(){
    int i=1;
    while (i<=4){
        int j=1;
        while (j<i){
            cout<<"  ";
            j++;
        }
        j=i;
        while (j<=4){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
/*Babbar Method -> Similar to Q8. I like mine better,but it is a little more complex*/