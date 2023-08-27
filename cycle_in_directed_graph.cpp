#include<bits/stdc++.h>


using namespace std;
const int N=1e3+10;
vector<int>graph[N];
stack<int>result;
bool vis[N];
int loop=0;

void dfs(int vertex) {
    vis[vertex] = true;
    for (int child : graph[vertex]) {
        if(vis[child]){
            loop++;
            return;
        }
        if (!vis[child]) {
            dfs(child);
        }
    }
    vis[vertex]=false;
}







void topologicalsort(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
}




int main(){


	int n,m;//n is vertex and m is edges (number)
	for(int i=0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
	}

    for(int i=0;i<n;i++){
        if(loop){cout<<"llop is here"; break;}
        dfs(i);


    }
    
	if(!loop){
	cout<<"not a loop"<<endl;}

    //topologicalsort(n);


}

