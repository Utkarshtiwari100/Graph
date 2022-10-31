/*
Code : Dijkstra's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int findMV(vector<int>& dist, vector<bool>& vis, int n) {
    int mv = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i] && (mv == -1 || dist[i] < dist[mv])) {
            mv = i;
        }
    }
    return mv;
}

void Dijkstra(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> dist(n);
    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        vis[i] = false;
    }
    dist[0] = 0;
    
    for(int i = 0; i < n-1; i++) {
        int mv = findMV(dist, vis, n);
        vis[mv] = true;
        for(int j = 0; j < n; j++) {
            if(edges[mv][j] && !vis[j]) {
                int newDist = dist[mv] + edges[mv][j];
                if(newDist < dist[j]) {
                    dist[j] = newDist;
                }
            }
        }
    }
    
    //Print
    for(int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>>edges (n, vector<int>(n, 0));
    
    for(int i = 0; i < e; i++) {
        int f, s, wt;
        cin >> f >> s >> wt;
        edges[f][s] = wt;
        edges[s][f] = wt;
    }
    
    Dijkstra(edges);
    
}

/*

int findMinVertex(int* distance, bool* visited, int n) {
    int minVertex = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int** edges, int n) {
    int* distance = new int[n];
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for(int i = 0; i < n-1; i++) {
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++) {
            if(edges[minVertex][j] && !visited[j] ) {
                int dest = distance[minVertex] + edges[minVertex][j];
                if(dest < distance[j]) {
                    distance[j] = dest;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << i << " " << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0; i < V; i++) {
        edges[i] = new int[V];
        for(int j = 0; j < V; j++) {
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < E; i++) {
        int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
    }
    
    dijkstra(edges, V);
    return 0;
}

*/

