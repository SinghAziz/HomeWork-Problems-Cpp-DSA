#include<iostream>
using namespace std;

void sort(int arr[4]){  
    int dump;  
    for (int j=0;j<4;j++){
    for (int i=0;i<4;i++){
        if (arr[i+1]<arr[i]){
            dump=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=dump;
        }
    }
    }
    // for (int i=0;i<4;i++){
    //      cout<<endl<<arr[i]<<endl;
    // }
}

int ispossible (int arr[5], int size, int mid){
    int sum=0;
    for (int i=mid;i<5;i++){
        if (sum+arr[i]-arr[mid]<20){
            sum+=arr[i]-arr[mid]; 
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int arr[]={4,42,40,26,46};
    int size=5;
    int e=size;
    int s=0;
    int mid=s+(e-s)/2;
    int ans=-1;
 
    sort(arr);

    while (s<=mid){ 
        
    if (mid>=0 ){
        if (ispossible(arr,size,mid)){
        mid--;
        
    }
    else{
        ans=arr[mid];  
        s++; 
    }
    }
    }
    cout<< "ans:"<<ans;

}