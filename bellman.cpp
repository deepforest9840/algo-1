#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9+10;
vector<int>dist(N,inf);
vector<int>vis(N);
vector<pair<int,int>>graph[N];
int n,m;
bool update;

void bellman(int source){

    dist[source]=0;
   for(int i=0;i<n-1;i++){
    

     
     for(int j=0;j<n;j++){

           for(auto child:graph[j]){

                int v=child.first;
                int wt=child.second;
                if(dist[j]!=inf && dist[j]+wt<dist[v]){
                    dist[v]=dist[j]+wt;
                }
           }


     }





   }


     for(int j=0;j<n;j++){

           for(auto child:graph[j]){

                int v=child.first;
                int wt=child.second;
                if(dist[j]!=inf && dist[j]+wt<dist[v]){
                    cout<<"negative weight cycle found"<<endl;
                    return;
                }
           }


     }

     






}

int main(){
    
    cin>>n>>m;
    for(int i=0;i<m;i++){

        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
    }
    bellman(0);

    for(int i=0;i<n;i++){

        cout<<dist[i]<<" ";
    }


}


