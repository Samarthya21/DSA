#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={3,5,4,1,2};

    int index=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(a[i]<a[j]){
            swap(a[i],a[j]);
              }
        }
    }
    for(int m=0;m<5;m++){
        cout<<a[m];
    }
}