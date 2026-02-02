#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertionsort(vector<int>&arr, int i, int n){
    //Base Case
    if (i==n) return;

    int j=i;
    while (j>0 && arr[j-1]>arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }

    insertionsort(arr, i+1, n);
}



int main(){

    vector<int> arr;
    arr={2, 3, 4,1,6};
    insertionsort(arr,0, arr.size());
    for ( int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}