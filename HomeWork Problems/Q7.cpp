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
    int i=1;
    int n=1;
    while (n<=4){
        i=n;
        while (i<=4){
        cout<<'*'<<" ";
        i++;
        }
    cout<<endl;
    n++;
    }
}
*/

/* Babbar Method
Uses Row and Input Value and 1 as a control unit for the first row
*/
int main(){
    int n;
    cin>>n;
    int i=1;
    while (i<=n){
        int j=1;
        while (j<=n-i+1){
            cout<<'*'<<" ";
            j++;
        }
        i++;
        cout<<endl;
    }
}
