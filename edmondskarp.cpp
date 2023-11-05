#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 100;  // Adjust the maximum number of nodes as needed

int graph[MAXN][MAXN];  // Residual graph
int parent[MAXN];       // Parent of each node in the augmenting path
int n;                 // Number of nodes

bool bfs(int source, int sink) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
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

        while (v != source) {
            int u = parent[v];
            minCapacity = min(minCapacity, graph[u][v]);
            v = u;
        }

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

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the source and sink nodes: ";
    cin >> source >> sink;

    cout << "Enter the edges (from to capacity), terminate with -1 -1 -1:" << endl;
    int from, to, capacity;

    while (true) {
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

