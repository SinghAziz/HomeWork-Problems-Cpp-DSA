//Check if string is a palindrome, ignore anything but alpha and numbers
#include<iostream>
using namespace std;

int main(){
    char str[9]={"Hel11leH"};
    int c;
    for (int i=0;i<7;i++){
        if (str[i]!=str[7-i]){
            cout<<"Noope";
            break;
        }
        else{
            c=1;
        }
    }
    if (c==1){
        cout<<"Yes";
    }

    int arr[][4]={ {1,2},{3,4}};
    cout<<arr[1][0];

}