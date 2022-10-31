/*

Code : Is Connected ?

Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 

*/

#include <iostream>
#include <vector>

using namespace std;

void isConnected(vector<vector<int> >& g, int v, int sv, vector<bool>& visited) {
    visited[sv] = true;
    for (int i = 0; i < v; ++i) {
        if (g[sv][i] && !visited[i]) {
            isConnected(g, v, i, visited);
        }
    }
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int> > g(v, vector<int>(v, 0));
    for (int i = 0; i < e; ++i) {
        int f, s;
        cin >> f >> s;
        g[f][s] = 1;
        g[s][f] = 1;
    }
    vector<bool> visited(v, false);
    isConnected(g, v, 0, visited);
    bool flag = false;
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            flag = true;
            cout << "false" << '\n';
            break;
        }
    }
    if (!flag) {
        cout << "true" << '\n';
    }
    return 0;
}


// #include <iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// bool isConnectedDFS(vector<vector<bool>>& edges, vector<bool>& visited, int n, int sv = 0) {
    
//     visited[sv] = true;
//     bool ans = false;
//     for(int i = 0; i < n && !ans; i++) {
//         if(!visited[i] && edges[sv][i]) {
//             ans = isConnectedDFS(edges, visited, n, i);
//             visited[i] = true;
//             if(ans == false ) return ans;
//         }
//     }
    
//     return true;
// }

// int main() {
//     int v, e;
//     cin >> v >> e;
//     vector<vector<bool>> edges(v, vector<bool>(v, false));
//     vector<bool> visited(v, false);
    
//     for(int i = 0; i < e; i++) { 
//         int a, b;
//         cin >> a >> b;
//         edges[a][b] = true;
//         edges[b][a] = true;
//     }
    

//     cout << (isConnected(edges, visited, v) ? "true" : "false");
    
// }


#include <iostream>
#include<vector>
#include<queue>
using namespace std;

/*
void dfs(vector<vector<bool>>& edges, vector<bool>& visited, int n, int sv) {
    visited[sv] = true;
    for(int i = 0; i < n ; i++) {
        if(!visited[i] && edges[sv][i]) {
            dfs(edges, visited, n, i);
            visited[i] = true;
        }
    }
    
}
bool isConnected(vector<vector<bool>>& edges, vector<bool>& visited, int n) {
    dfs(edges, visited, n, 0);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            return false;
        }
    }
    return true;
}
*/

/*
bool isConnectedDFS(vector<vector<bool>>& edges, vector<bool>& visited, int n, int sv) {
    
    visited[sv] = true;
    bool ans = false;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && edges[sv][i]) {
            ans = isConnectedDFS(edges, visited, n, i);
            visited[i] = true;
            if(ans == false ) return ans;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            return false;
        }
    }
    return true;
    
}
bool isConnectedBFS(vector<vector<bool>> edges, vector<bool> visited, int n, int sv) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    
    while( !q.empty()) {
        int fr = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            if(!visited[i] && edges[fr][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    int i = 0;
    for(; i < n; i++) {
        if( !visited[i]) {
            return false;
            break;
        }
    }
    if(i == n) {
        return true;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<bool>> edges(v, vector<bool>(v, false));
    vector<bool> visited(v, false);
    
    for(int i = 0; i < e; i++) { 
        int a, b;
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
    

    cout << (isConnectedDFS(edges, visited, v, 0) ? "true" : "false");
    
}
*/