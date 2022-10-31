/**********************************************



Code : All connected components

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :

Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

**********************
Sample Input 1:
4 2
0 1
2 3

Sample Output 1:
0 1 
2 3 

********************

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
0 1 3 
2


************************************************/


#include <bits/stdc++.h>
using namespace std;

vector<int> printBFS(vector<vector<int>>& g, vector<bool>& vis, int n, int s) {
    vector<int> ans;
    
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        for(int i = 0; i < n; i++) {
            if( !vis[i] && g[front][i] == 1) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return ans;
}

void printConnectedComponents(vector<vector<int>>& g, vector<bool>& visited, int n, int sv) {
    vector<int> ans = printBFS(g, visited, n, sv);
    
    sort(ans.begin(), ans.end());
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, 0));
    
    for(int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        g[f][s] = 1;
        g[s][f] = 1;
    }
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            printConnectedComponents(g, visited, v, i);
        }
    }
    
    
    return 0;
}

/*
void printDFSHelper(int** edges, bool* visited,int n, int sv, vector<int>& ans) {

    ans.push_back(sv);
    
    visited[sv] = true;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && edges[sv][i] == 1) {
            printDFSHelper(edges, visited, n, i, ans);
        }
    }
    
}
void printDFS(int** edges, bool* visited,int n, int sv) {
    vector<int> ans;
    printDFSHelper(edges, visited, n, sv, ans);
    sort(ans.begin(), ans.end());
    for(auto i : ans) {
        cout << i << " ";
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
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            printDFS(edges, visited, V, i);
            cout << endl;
        }
    }
    
    for(int i = 0; i < V; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
    
}
*/