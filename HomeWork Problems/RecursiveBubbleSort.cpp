#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;


void bubblesort(vector<int>&arr, int n){

    if (n==1) return;
    for (int i =0; i<=n-2;i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    bubblesort(arr, n-1);
}

int main(){
    vector<int> arr;
    arr={1, 0, 1, 2, 1};
    bubblesort(arr,arr.size());
    for (int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}