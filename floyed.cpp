#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9+10;
int dist[N][N];



int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else {
                dist[i][j]=inf;
            }
        }
    }


    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        dist[x][y]=z;

    }


    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                if(dist[i][k]!=inf && dist[k][j]!=inf){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

                }

            }
        }
    }


      for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(dist[i][j]==inf){
                    cout<<"I ";
                }
                else cout<<dist[i][j]<<" ";

            }
            cout<<endl;
        }


    for(int i=1;i<=n;i++){
        if(dist[i][i]<0){
            cout<<"negative weighted cycle exists"<<endl;
        }
    }

    



}
