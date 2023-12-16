#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={3,5,4,1,2};

    int index=0;
    for(int i=1;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
              }
        }
    }

    for(int m=0;m<5;m++){
        cout<<a[m];
    }
}