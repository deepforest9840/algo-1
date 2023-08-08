#include<bits/stdc++.h>
using namespace std;
const int N=1e1+10;

vector<int>g[N];
bool vis[N];
bool path_vis[N];
bool path_flag=false;
queue<int>path_queue;

vector<int>disc(N,-1);
vector<int>low(N,-1);
vector<int>parent(N,-1);
vector<bool>art_p(N,false);
int new_path_queue_vertex[N];
//vector<int>graph[N];
vector<pair<int,int>>bridge;
set<pair<int,int>>s;

int deg[N];
set<pair<int,int>>deg_s;

//unordered_set<int>circuitt_set;
vector<pair<int,int>>cirss;


bool isexists[N][N];


queue<int>new_path_queue;

set<pair<int,int>>new_path_set;
vector<pair<int,int>>new_path_ans;


vector<int>path_ans;
void dfs(int vertex){


    //cout<<vertex<<" ";
    vis[vertex]=true;
    for(auto child:g[vertex]){

       // cout<<"from: "<<vertex<<" to: "<<child<<endl;
        if(!isexists[vertex][child]){
                cirss.push_back({vertex,child});

                isexists[vertex][child]=true;
                isexists[child][vertex]=true;
            
        }

    //    // cirs.insert({vertex,child});
    //     if(cirs.find({child,vertex})!=cirs.end()){
    //         cirs.erase({child,vertex});
    //     }
        if(!vis[child]){

                dfs(child);
        }

    }
}

void path_bridge(int vertex){

    static int time=0;
    disc[vertex]=low[vertex]=time;
    time++;
    int children=0;
    for(int child:g[vertex]){

        if(disc[child]==-1){

            children++;
            parent[child]=vertex;
            path_bridge(child);
            low[vertex]=min(low[vertex],low[child]);
            if(low[child]>disc[vertex]){
				bridge.push_back({vertex,child});
                s.insert({vertex,child});
                s.insert({child,vertex});
			}



        }
        else if(child!=parent[vertex]){
            low[vertex]=min(low[vertex],disc[child]);
        }





    }


}

// void path_dfs(int vertex){

//     path_vis[vertex]=true;
//     path_ans.push_back(vertex);
//     for(auto child:g[vertex]){
       
//         if(!path_vis[child]){

//  if(s.find({vertex,child})!=s.end()){
//             path_queue.push(child);
            
//             continue;
//         }

//             path_dfs(child);
//         }


//     }
//    if(!path_queue.empty()){


//         int a=path_queue.front();
//         cout<<"value from queue is :"<<a<<endl;

//         if(!path_vis[a]){
//         path_queue.pop();
        
//         path_dfs(a);
//         }
//    }

// }



void new_path_dfs(int vertex){
        if(new_path_set.empty()){
            return;
        }
        for(auto child:g[vertex]){

            if(new_path_set.find({vertex,child})!=new_path_set.end()){
                    if(s.find({vertex,child})!=s.end()){
            new_path_queue.push(child);
            new_path_queue_vertex[child]=vertex;
            new_path_set.erase({vertex,child});
                    new_path_set.erase({child,vertex});

            
            continue;
        }
                    new_path_ans.push_back({vertex,child});
                    new_path_set.erase({vertex,child});
                    new_path_set.erase({child,vertex});


                    new_path_dfs(child);
            }
        }


     if(!new_path_queue.empty()){


        int a=new_path_queue.front();
        cout<<"value from queue is :"<<a<<endl;
        int vertex=new_path_queue_vertex[a];
        new_path_ans.push_back({vertex,a});
         // new_path_set.erase({vertex,a});
          // new_path_set.erase({a,vertex});
    //    if(){
        new_path_queue.pop();
        
       new_path_dfs(a);
     }
        //}
   }






int main(){

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){


        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
        deg[v1]++;
        deg[v2]++;
        deg_s.insert({deg[v1],v1});
        deg_s.insert({deg[v2],v2});

        new_path_set.insert({v1,v2});
        new_path_set.insert({v2,v1});

    }

    int path=0;
    int circuit=0;
    int odd=0;
    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            odd++;
        }
        else if(g[i].size()%2!=0){
            odd++;
        }

    }

    cout<<"odd value is: "<<odd<<endl;
    if(odd>2){
        cout<<"no euler path or circuit"<<endl;
    }

   else if(odd==2){
        path=1;
    }
   else if(odd==0){
        circuit=1;
    }

    if(circuit){
        cout<<"euler circuit is exists and edges are "<<endl;
        dfs(1);

        for(auto i:cirss){
            cout<<i.first<<" "<<i.second<<endl;
        }
        
        
        }
    if(path){



        cout<<"euler path exists"<<endl;

        auto it=(--deg_s.end());

        while((*(it)).first%2==0){

            if((*it).first==1){
                break;
            }
            it--;

        }

        cout<<(*it).second<<" deg is "<<(*it).first<<endl;

        //sort(deg,deg+N,greater<int>());
       for(int i=1;i<=n;i++){
        if(disc[i]==-1){
            path_bridge(i);
        }
    }
        for(auto i:bridge){
            cout<<" vetex is "<<i.first<<" edge is "<<i.second<<endl;
        }

        cout<<" output from the set"<<endl;
        for(auto i:s){
            cout<<i.first<<" edge is "<<i.second<<endl;
        }

       // path_dfs((*it).second);



       // cout<<"euler path is"<<endl;
       // path_ans.push_back(4);
       // path_ans.push_back(7);
       // for(auto child:path_ans){
        //    cout<<child<<" ";
      //  }

        new_path_dfs((*it).second);


        cout<<"new euler path ans "<<endl;
        for(auto i:new_path_ans){

            cout<<i.first<<" "<<i.second<<endl;
        }


    }


}































