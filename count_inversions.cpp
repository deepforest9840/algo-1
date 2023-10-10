#include<bits/stdc++.h>
using namespace std;
int merge(int ar[],int l,int mid,int r){

    int inv=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=ar[i+l];
    }
    for(int i=0;i<n2;i++){
        b[i]=ar[i+mid+1];
    }

    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(a[i]<=b[j]){

            ar[k]=a[i];
            k++;i++;
        }
        else{
            ar[k]=b[j];
            k++;j++;
            inv+=n1-i;
        }
    }
    while(i<n1){
        ar[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        ar[k]=b[j];
        k++;j++;
    }
    return inv;

}
int mergesort(int ar[],int l,int r){
    int inv=0;
    
    if(l<r){
        int mid=(l+r)/2;
        inv+=mergesort(ar,l,mid);
        inv+=mergesort(ar,mid+1,r);
        inv+=merge(ar,l,mid,r);
    }
    return inv;
    
}
int main(){
    int n;
    cin>>n;
   int ar[n];
   for(int i=0;i<n;i++){
    cin>>ar[i];
   }
  

   cout<<endl<<mergesort(ar,0,n-1);
   cout<<endl<<"array is"<<endl;
    for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
   }
}
