#include<bits/stdc++.h>
using namespace std;
using namespace std;
const int MAXN = 100;
nodes as needed
// Adjust the maximum number ofint graph[MAXN][MAXN]; // Residual graph
int parent[MAXN];
// Parent of each node in the
augmenting path
int n;
// Number of nodes
bool bfs(int source, int sink) {
vector<bool> visited(n+1, false);
queue<int> q;
q.push(source);
visited[source] = true;
parent[source] = -1;
while (!q.empty()) {
int u = q.front();
q.pop();
for (int v = 1; v <= n; v++) {
if (!visited[v] && graph[u][v] > 0) {
q.push(v);
parent[v] = u;
visited[v] = true;
}
}
}
return visited[sink];
}
int edmondsKarp(int source, int sink) {
int maxFlow = 0;
while (bfs(source, sink)) {
int minCapacity = INT_MAX;
int v = sink;
stack<int>path;
path.push(v);
while (v != source) {int u = parent[v];
path.push(u);
minCapacity = min(minCapacity, graph[u][v]);
v = u;
}
cout<<endl<<" augment path is: ";
while(!path.empty()){
cout<<path.top()<<" ";
path.pop();
}
cout<<endl;
v = sink;
while (v != source) {
int u = parent[v];
graph[u][v] -= minCapacity;
graph[v][u] += minCapacity;
v = u;
}
maxFlow += minCapacity;
}
return maxFlow;
}
int main() {
int source, sink;
//cout << "Enter the number of nodes: ";
cin >> n;
//cout << "Enter the source and sink nodes: ";
cin >> source >> sink;
// cout << "Enter the edges (from to capacity), terminate
with -1 -1 -1:" << endl;
int from, to, capacity;
int eddd;
cin>>eddd;for(int ed=0;ed<eddd;ed++) {
cin >> from >> to >> capacity;
if (from == -1 || to == -1 || capacity == -1) {
break;
}
graph[from][to] = capacity;
}
int maxFlow = edmondsKarp(source, sink);
cout << "Max Flow: " << maxFlow << endl;
return 0;
}
