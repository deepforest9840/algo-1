#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int par[N];
int sz[N];
void make(int v){
    par[v]=v;
    sz[v]=1;
}
int find(int v){
    if(v==par[v]){
        return v;
    }
    return par[v]=find(par[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[b]>sz[a]){
            swap(a,b);
        }
        par[b]=a;
        sz[a]+=sz[b];
    }
}
int main(){


int n,m;
cin>>n>>m;
vector<pair<int,pair<int,int>>>edges;
for(int i=1;i<=n;i++){
    make(i);
}
for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back({c,{a,b}});


}
sort(edges.begin(),edges.end());
int total=0;
    for(auto edge:edges){
            
            int wt=edge.first;
            int u=edge.second.first;
            int v=edge.second.second;
            if(find(u)==find(v)){
                continue;
            }
            Union(u,v);
            cout<<u<<" "<<v<<endl;

            total+=wt;
    }
    cout<<total<<endl;

























}














