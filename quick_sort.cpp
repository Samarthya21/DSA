#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int s,int e){
    
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivot_index=s+count;
    
    swap(arr[pivot_index],arr[s]);
    int i=s;
    int j=e;
    while(i<pivot_index && j>pivot_index){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivot_index && j>pivot_index){
            swap(arr[i++],arr[j--]);
        }
    }
  return(pivot_index);
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    //partitioning
    int p=0;
    p=partition(arr,s,e);
    //recursive curve
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int arr[]={3,1,2,8,5,4};
    int l=sizeof(arr)/sizeof(arr[0]);
    int s=0;
    int e=l-1;
    quicksort(arr,s,e);
  for(int i=s;i<=e;i++){
    cout<<arr[i];
  }
}