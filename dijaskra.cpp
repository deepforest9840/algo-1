#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9+10;
vector<int>dist(N,inf);
vector<int>vis(N);
vector<pair<int,int>>graph[N];

void dijkstra(int source){

    dist[source]=0;
    set<pair<int,int>>st;
    st.insert({0,source});
    while(!st.empty()){

        auto node=(*st.begin());
        int    v=node.second;
        int v_dist=node.first;
         st.erase(st.begin());
        if(vis[v])continue;
        vis[v]=1;
     
       
        for(auto child:graph[v]){
            int wt=child.second;
            int child_v=child.first;
            if((wt+dist[v])<dist[child_v]){
                dist[child_v]=wt+dist[v];
                st.insert({dist[child_v],child_v});


            }


        }
        




    }







}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){

        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
    }
    dijkstra(1);

    for(int i=1;i<=n;i++){

        cout<<dist[i]<<" ";
    }


}


