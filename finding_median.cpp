#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+10;


void lineartimeselection(int ar[],int n,int k){


    
    
    if(n<6){

        sort(ar,ar+n);


        cout<<"the number is "<<ar[k]<<endl;
        return;


    }
    else{
            int group=n/5;
            int k1=0;
            int b[group][5];
            for(int i=0;i<group;i++){
                for(int j=0;j<5;j++){
                    if(k1<=n){
                        b[i][j]=ar[k1];
                        k1++;
                    }
                    else{
                        b[i][j]=inf;
                         continue;
                    }
                   


                }
            }
            cout<<endl<<" the five array is ";
            for(int i=0;i<group;i++){
                for(int j=0;j<5;j++){
                   cout<<b[i][j]<<" ";
                }
                cout<<endl;
            }
        

            for(int i=0;i<group;i++){
                sort(b[i],b[i]+5);

            }

            int b2[group];
            k1=0;
            for(int i=0;i<group;i++){

                if(b[i][2]!=inf){
                    b2[i]=b[i][2];
                    k1++;
                }
            }
            sort(b2,b2+k1);
            int com=b2[2];
            cout<<endl<<"first comparator is "<<com<<endl;
            
            int A[n];
            int i=0;
            k1=0;
            for( i;i<n;i++){
                if(ar[i]<com){
                    A[k1]=ar[i];
                    k1++;
                }

            }

            if(k1>k){
                     cout<<endl<<" from the left part"<<endl;
                
                for(int  i=0;i<k1;i++){
                    cout<<A[i]<<" ";
                } 
               return  lineartimeselection(A,k1,k);
            }
            else if(k1==k){
                cout<<" the number is com "<<com<<endl;
                return ;
            }
            else{
                int si=0;
                for(int i=k1+1, j=0;i<n;i++,j++){
                    A[j]=ar[i];
                    si++;
                    
                }
                return lineartimeselection(A,si,si/2);
            }



    }



}










int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
   int ar[n];
   for(int i=0;i<n;i++){
    cin>>ar[i];
   }
  

  lineartimeselection(ar,n,n/2);
}
