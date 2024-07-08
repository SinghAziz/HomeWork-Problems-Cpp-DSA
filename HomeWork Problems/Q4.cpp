/*
A B C
A B C
A B C

for n=3
*/

#include<iostream>
using namespace std;

int main()
{
    int i=1;
    while (i<=3){
        int j=1;
        char ch = 'A';
            while (j<=3){
                cout<<ch<<" ";
                ch++;
                j++;
            }
        cout<<endl;
        i++;
    }
}