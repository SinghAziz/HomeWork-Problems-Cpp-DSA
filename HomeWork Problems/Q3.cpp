/*
1
2 1 
3 2 1 
4 3 2 1

Hint: Subtract column number from row number and add 1. (r-c+1)
*/

#include<iostream>
using namespace std;

/*My Method:
Time: exited with code=0 in 0.967 seconds
int main()
{
    int r=1,c=1;
    while (r<=4){
        r=c;
        while (r>0){
            cout<<r<<" ";
            r-=1;
        }
        cout<<endl;
        c+=1;
        r=c;
    }
    
}
*/

/* Using i-j+1 (Faster)
Used in Lecture
Time: exited with code=0 in 0.897 seconds
*/

int main()
{
    int i=1,j=1;
    while (i<=4){
        j=1;
        while (j<=i){
            cout<<i-j+1<<" ";
            j+=1;
        }
        i++;
    cout<<endl;
    }
}