/* Problem Statement
* * * *
  * * *
    * *
      * 
*/

#include<iostream>
using namespace std;

/* My Method
int main(){
    int i=1,n;
    cin>>n;
    //3+i-n, split in 2 triangles, i.e. pehle spaces then taare
    while (i<=n){
        int j=1;
        while (j<=3+i-n){
            cout<<"  ";
            j++;
        }
        while (j<=n){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/

/* Babbar Method*/
int main(){
    int n;
    cin>>n;
    int i=1;
    while (i<=n){
        int j=1, space=1;
        while (space< i){
            cout<<" ";
            space+=1;   
        }
        while (j<=n-i+1){
            cout<<"* ";
            j+=1;  
        }
        i+=1;
        cout<<endl;
    }
}