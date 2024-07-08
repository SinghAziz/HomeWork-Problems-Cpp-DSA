/*Problem Statement
4
A
B C
C D E
D E F G
*/

#include<iostream>
using namespace std;

int main(){
    int i=1;
    int n;
    cin>>n;
    
    while (i<=n){
        char ch=64+i;
        int j=1;
        while (j<=i){
            cout<<ch<<" ";
            ch=ch+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// int main(){
//     int i=1;
//     char ch=65+i;
//     cout<<ch;
// }