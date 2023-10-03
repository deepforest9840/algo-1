#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
 int ss=0;
int c[50][50];
int ar[50][50];

void printbest(int i,int j){
     cout<<"i is "<<i<<" j is "<<j<<endl;
    if(i==0){
        return;
    }
 

    if((ar[i-1][j-1]<=ar[i-1][j])and(ar[i-1][j-1]<=ar[i-1][j+1])){
         cout<<"i is "<<i<<" j is "<<j<<endl;
        printbest(i-1,j-1);
    }
   
    else if((ar[i-1][j]<=ar[i-1][j-1])and(ar[i-1][j]<=ar[i-1][j+1])){
         cout<<" from middle i is "<<i<<" j is "<<j<<endl;
        printbest(i-1,j);
    }
    else if((ar[i-1,j+1]<=ar[i-1,j-1]) and (ar[i-1][j+1]<=ar[i-1][j])){
         cout<<"i is "<<i<<" j is "<<j<<endl;
        printbest(i-1,j+1);
    }
     
   


}





void rock(int row,int col){
    ss=col+1;
    
    
    for(int i=0;i<row+1;i++){

        for(int j=0;j<col+2;j++){

                if(i==0){
                    ar[i][j]=0;
                }
               else if(j==0||j==col+1){
                    ar[i][j]=inf;
                }
            else  if(i==1){
                    ar[i][j]=c[i-1][j-1];
                }
                else {
                    ar[i][j]=c[i-1][j-1]+min(min(ar[i-1][j-1],ar[i-1][j]),ar[i-1][j+1]);
                    

                }

        }
    }


        for(int i=0;i<row+1;i++){
            for(int j=1;j<col+1;j++){
                    cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }

int ans=inf;
int r,co;
        for(int j=1;j<col+1;j++){
                ans=min(ans,ar[row][j]);
        }
        cout<<"min answer is"<<ans<<endl;
        for(int j=1;j<col+1;j++){
                if(ans==ar[row][j]){
                    cout<<"row is "<<row-1<< " col is "<<j-1<<endl;
                    r=row,co=j;
                
                }
        }

    cout<<endl<<"answer"<<endl;
    cout<<c[r-1][co-1]<<" "<<c[r-2][co-1]<<" "<<c[r-3][co]<<" "<<c[r-4][co-1]<<endl;
        printbest(r,co);

  cout<<"my last answer is "<<endl;
    while(r>0){
        cout<<c[r-1][co-1]<<" ";
        ans=ar[r][co]-c[r-1][co-1];
        r--;
         for(int j=1;j<col+1;j++){
                if(ans==ar[r][j]){
                   
                    co=j;
                
                }
        }

    }




}

int main(){
     freopen("input.txt","r",stdin);
    
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){

                cin>>c[i][j];
        
        }
    }
    rock(4,5);
   
 



}
