#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int inf=1e9+10;
vector<int>dist(N,inf);
vector<int>vis(N);
vector<pair<int,int>>graph[N];
int n,m;
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

void bellman(int source) {
    dist[source]=0;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n; j++) {
            for(auto child : graph[j]) {
                int v = child.first;
                int wt = child.second;
                if(dist[j] != inf && dist[j] + wt < dist[v]) {
                    dist[v] = dist[j] + wt;
                }
            }
        }
    }

    for(int j=0; j<n; j++) {
        for(auto child : graph[j]) {
            int v = child.first;
            int wt = child.second;
            if(dist[j] != inf && dist[j] + wt < dist[v]) {
                cout << "Negative weight cycle found" << endl;
                return;
            }
        }
    }
}

void johnson() {
    // Step 1: Add a new vertex with zero-weight edges to all other vertices
    for(int i = 1; i <= n; i++) {
        graph[0].push_back({i, 0});
    }

    // Step 2: Run Bellman-Ford algorithm to calculate potential function h[v]
    bellman(0);

    // Step 3: Remove the added vertex and modify edge weights using the potential function
    for(int i = 0; i <= n; i++) {
        for(auto& child : graph[i]) {
            child.second += dist[i] - dist[child.first];
        }
    }

    int ans[N][N];

    // Step 4: Run Dijkstra's algorithm for each vertex to find shortest paths
    for(int i = 1; i <= n; i++) {
        fill(dist.begin(), dist.end(), inf);
        fill(vis.begin(), vis.end(), 0);
        dijkstra(i);

        for(int j = 1; j <= n; j++) {
            ans[i][j]=dist[j];
        }
    }

    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(ans[i][j]==inf){
                    cout<<"I ";
                }
                else cout<<ans[i][j]<<" ";

            }
            cout<<endl;
        }
    
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2, wt});
    }
    johnson();
}

