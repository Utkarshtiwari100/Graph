/*
Code : Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int> > map;
        
        for(auto i : edges) {
            
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        
        vector<bool> vis(n+1, false);
        
        queue<int> q;
        q.push(source);
        vis[source] = true;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
              // vector<int> temp = map[front];
                for(auto i : map[front]) {
                    int vertex = i;
                    if(vis[vertex] == false) {
                        q.push(vertex);
                        vis[vertex] = true;
                    }
                }
             if(vis[destination] ) return true;
        }
    
        return vis[destination];
    }

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int> > edges(V, vector<int>(V, 0));
    
    
    for(int i = 0; i < E; i++) {
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    
    validPath(V, edges, v1, v2) ?  cout<<"true" :  cout<<"false";
}


/*
//using DFS
bool hasPath(vector<vector<int>>& graph, int n, vector<bool>& visited, int s, int e) {
    
    if(s == e) return true; // when elements are same.
    
    visited[s] = true;
    bool ans = false;
    
    for(int i = 0; i < n; i++) {
        
        if(!visited[i] && graph[s][i] == 1) {
			if(hasPath(graph, n, visited, i, e) ) return true;
        }
        
    }
    
    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> graph(V, vector<int>(V, 0));
    
    for(int i = 0; i < E; i++) {
        int f, s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    vector<bool> visited(V, false);
    
    int v1, v2;
    cin >> v1 >> v2;
    
    cout << (hasPath(graph, V, visited, v1, v2) ? "true" : "false");
}
*/

/*
//Using BFS
bool traversal(vector<vector<int>>& edges, int n, int startingVertex, vector<bool>& visited, int v1, int v2) {
    
    queue<int> q;
    q.push(startingVertex);
    visited[startingVertex] = true;
    bool ans = false;
    
    while(!q.empty()) {
        if(edges[v1][v2] == 1) {
            return true;
        }
        int currentVertex = q.front();
        q.pop();
        
        for(int i = 0; i < n; i++) {
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    if(visited[v2] && visited[v1])
        ans = true;
    return ans;
}

bool hasPath(vector<vector<int>>& edges, int n, vector<bool>& visited, int s, int e) {
  
	for(int i = 0; i < n; i++) {
        if(!visited[i]) {
           return traversal(edges, n, i, visited,s , e);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int> > edges(V, vector<int>(V, 0));
    
    vector<bool> visited(V, false);
    
    for(int i = 0; i < E; i++) {
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    
    // if(hasPath(edges, V, visited, v1, v2)) {
    //     cout<<"true";
    // }
    // else {
    //     cout<<"false";
    // }
    hasPath(edges, V, visited, v1, v2) ?  cout<<"true" :  cout<<"false";
}
*/