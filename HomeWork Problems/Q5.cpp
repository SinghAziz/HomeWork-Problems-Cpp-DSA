/* Problem Statement
A
B C
D E F
G H I J
*/

#include<iostream>
using namespace std;

int main()
{
    int i=1;
    char ch='A';
    while (i<=4){
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