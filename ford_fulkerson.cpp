#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int graph[N][N];
int parent[N];
bool visited[N];
int n;


bool dfs(int s,int t){

    memset(visited,0,sizeof(visited));
    visited[s]=true;
    parent[s]=-1;
    stack<int>st;
    st.push(s);

    while(!st.empty()){
        int u=st.top();
        st.pop();

        for(int v=1;v<=n;v++){



            if(!visited[v]&& graph[u][v]>0 ){


                    parent[v]=u;
                    visited[v]=true;
                    st.push(v);




            }



        }
    }


    return visited[t];






}

int fordfulkerson(int s,int t){

        int maxflow=0;
        while(dfs(s,t)){//this code helps us to find the augmenting path


        int minc=INT_MAX;
        int v=t;
    //here we find the minimum capacity
        cout<<endl<<"aug path is "<<v;
        while(v!=s){
            
            int u=parent[v];
            cout<<" "<<u;
            minc=min(minc,graph[u][v]);
            v=u;

        }

        v=t;
        //lets update the residual graph

        // the original graph contains u--v(c)..
        //but u--v means the remainig capacity 
        //v--u contains the flow or total flow...the u--v ==0 means the capacity is full
        while(v!=s){
            int u=parent[v];
            graph[u][v]-=minc;
            graph[v][u]+=minc;
            v=u;
        }

        maxflow +=minc;


        }



    return maxflow;


}
int main(){

        freopen("input.txt","r",stdin);
    int source,sink;
  //  cout<<"enter number of nodes"<<endl;
    cin>>n;
   // cout<<endl<<"enter the source and sink node"<<endl;
    cin>>source>>sink;

  //  cout<<"enter the edges ,from,to ,capacity"<<endl;
    int f,t,c;
   // cout<<"when all the edges is complete then input -1"<<endl;
    while(true){
            cin>>f>>t>>c;
            if(f==-1){
                break;
            }
            graph[f][t]=c;
 graph[t][f] = 0;


    }

    int maxf=fordfulkerson(source,sink);
    cout<<endl<<"this is ans "<<maxf<<endl;
  //  cout<<"test "<<graph[1][5];


}
