#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//using DFS
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int n, int sv) {
    visited[sv] = true;
    for(int i = 0; i < n; i++) {
        if( !visited[i] && graph[sv][i]) {
            dfs(graph, visited, n, i);
        }
    }
}

//using BFS
void bfs(vector<vector<int>>& graph, vector<bool>& marked, int n, int sv) {
    queue<int> pv;
    pv.push(sv);
    marked[sv] = true;
    while( !pv.empty()) {
        
        for(int i = 0; i < n; i++) {
            if(!marked[i] && graph[pv.front()][i]) {
                pv.push(i);
                marked[i] = true;
            }
        }
        pv.pop();
    }
}

int numIslands(vector<vector<int>>& graph, int n) {
    int total = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if( !visited[i]) {
            total++;
            // dfs(graph,visited, n, i);
            bfs(graph, visited, n, i);
        }
    }
    return total;
}
         
int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));
    
    for(int i = 0; i < numEdges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    cout << numIslands(graph, numVertices);
    
}

/*
#include <iostream>
#include <queue>
using namespace std;
void bfs(bool **edges, long long v, long long sv, bool *visited)
{
    queue<long long> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        for (long long i = 0; i < v; i++)
        {
            if (i == pendingVertices.front())
                continue;
            if (visited[i])
                continue;
            if (edges[pendingVertices.front()][i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
        pendingVertices.pop();
    }
}

int main()
{
    long long v, e;
    cin >> v >> e;
    bool **edges = new bool *[v];
    for (long long i = 0; i < v; i++)
    {
        edges[i] = new bool[v];
        for (long long j = 0; j < v; j++)
        {
            edges[i][j] = false;
        }
    }
    for (long long i = 0; i < e; i++)
    {
        long long start, end;
        cin >> start >> end;
        edges[start][end] = true;
        edges[end][start] = true;
    }
    bool *visited = new bool[v];
    for (long long i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (long long i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            count++;
            bfs(edges, v, i, visited);
        }
    }
    cout << count;
    return 0;
}
*/