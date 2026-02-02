#include<iostream>
using namespace std;

int main(){
    vector<int> arr={-10, 12, -3, 5, -6, 7, -8, 9};
    int i = 0 ;
    int j = arr.size() - 1;
    vector<int> pos;
    vector<int> neg;

    //With extra space and in order
    for (auto k : arr){
        if (k>=0){
            pos.push_back(k);
        }
        else{
            neg.push_back(k);
        }
    }
    for (auto h : neg){
        pos.push_back(h);
    }
    for (auto x: pos){
        cout<<x<<" ";
    }
    //Without extra space and without order
    // while(j){
    //     while (arr[i]>0) i++;
    //     while (arr[j]<=0) j--;
    //     swap (arr[i],arr[j]);
    // } 
    return 0;
}