#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<vector<int>>g[N];
vector<int>dist(N);
vector<bool>vis(N);
vector<int>ans;
int n,m;

const int INF=1e9;
int cost=0;
void primMst(int source){


    for(int i=0;i<n;i++)

    {
            dist[i]=INF;

    }
    dist[source]=0;
    set<vector<int>>s;
    s.insert({0,source});
    while(!s.empty()){

        auto x=*(s.begin());
        s.erase(x);
        
    vis[x[1]]=true;
    int u=x[1];
    int wt=x[0];
    cout<<u<<" "<<wt<<endl;
    ans.push_back(u);
    cost +=wt;

    for(auto it:g[x[1]]){

        if(vis[it[0]]){
            continue;
        }
        if(dist[it[0]]>it[1]){

            s.erase({dist[it[0]],it[0]});
            dist[it[0]]=it[1];
            s.insert({dist[it[0]],it[0]});
        }

    }
 }
 


}






int main(){


   // int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
       // g[u].push
        g[u].push_back({v,w});
        g[v].push_back({u,w});


    }
    primMst(0);
    cout<<"total cost is "<<cost;




}
