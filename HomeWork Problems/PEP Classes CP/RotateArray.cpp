#include<iostream>
using namespace std;

// void rotateArray(vector<int>& arr, int n, int k) {
//     int N = k>n || k<0 ? (n%2 + n)%k : k  ;
//     vector<int> ans(n);
//     for (int i =0 ;i<N; i++) ans[i+N]=arr[i];
//     for (int i =N ;i<n; i++) ans[i-N]=arr[i];
//     for (auto i: ans){
//         cout<<i<<" ";
//     }
// }

int main(){
    int n;
    // cin>>n;
    vector<int> arr{1,2,3,4,5,6,7};
    // for (int i = 0; i < n; i++) {
    //     cin>>arr[i];
    // }
    int k = 2;
    n = arr.size();
    if (k<0) k=n+k;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+k+1);
    reverse(arr.begin()+k, arr.end());
    for (auto i: arr){
        cout<<i<<" ";
    }
    // cin>>k;
    // rotateArray(arr, arr.size(), k);

}   