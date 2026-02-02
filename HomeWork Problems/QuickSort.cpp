
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;




int partition(vector<int>&  arr, int low, int high) {
    int pivot = arr[low];
    int i = low ;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot && i < high) i++;
        while (arr[j] > pivot && j > low) j--;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
        
    }
    swap(arr[j], arr[low]); // Place pivot in the correct position
    return j;
}


vector<int> quicksort(vector<int>& arr, int low , int high){
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
    return arr;
}

int main(){
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    arr = quicksort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout<<  num << " ";
    }
    return 0;
}
