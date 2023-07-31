#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>disc(N,-1);
vector<int>low(N,-1);
vector<int>parent(N,-1);
vector<bool>art_p(N,false);
vector<int>graph[N];
vector<pair<int,int>>bridge;
//for(int )
void dfs(int vertex){

    static int time=0;
    disc[vertex]=low[vertex]=time;
    time++;
    int children=0;
    for(int child:graph[vertex]){

        if(disc[child]==-1){

            children++;
            parent[child]=vertex;
            dfs(child);
            low[vertex]=min(low[vertex],low[child]);
            if(low[child]>disc[vertex]){
				bridge.push_back({vertex,child});
			}



        }
        else if(child!=parent[vertex]){
            low[vertex]=min(low[vertex],disc[child]);
        }





    }


}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=0;i<n;i++){
        if(disc[i]==-1){
            dfs(i);
        }
    }


    for(auto i:bridge){
		cout<<i.first<<"  "<<i.second<<endl;
	}

}
