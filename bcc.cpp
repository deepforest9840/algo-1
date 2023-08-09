#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;

vector<int>g[N];
bool vis[N];
vector<int>disc(N,-1);
vector<int>low(N,-1);
stack<pair<int,int>>edges;
vector<pair<int,int>>components[N];
int n_com=0;

int t=0;
void dfs(int vertex,int parent){

    
    disc[vertex]=low[vertex]=t++;
    int children=0;
    for(auto child:g[vertex]){
       

        if(disc[child]==-1){

            children++;
            edges.push({vertex,child});
            dfs(child,vertex);
            low[vertex] = min(low[vertex], low[child]);
            if((disc[vertex]==0 && children>1)|| (disc[vertex]>0&&low[child]>=disc[vertex])){


                while(!(edges.top().first==vertex && edges.top().second==child)){
                        components[n_com].push_back(edges.top());
                        edges.pop();
                }
                components[n_com].push_back(edges.top());
                edges.pop();
                n_com++;

            }

            }

            else if(parent!=child){
                low[vertex]=min(low[vertex],disc[child]);
                if(disc[child]<disc[vertex]){

                    edges.push({vertex,child});
                }
            }


            
        }

    


}

void bcc(int vertex){

        for(int i=1;i<=vertex;i++){
            if(disc[i]==-1){


                dfs(i,-1);
                bool sm=true;
                while(!edges.empty()){
                        sm=false;
                    components[n_com].push_back(edges.top());
                    edges.pop();
                }
                if(!sm){
                    n_com++;
                }


            }
        }




}
int main(){



    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bcc(n);
    for(int i=0;i<n;i++){
        if(components[i].size()>0){
            for(auto it:components[i]){
                cout<<it.first<<" ---"<<it.second<<" ";
            }
            cout<<endl;
        }

    }

}
