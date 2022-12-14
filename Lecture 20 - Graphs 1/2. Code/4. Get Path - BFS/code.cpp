/*
Code : Get Path - BFS

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getPathBFS(vector<vector<bool>>& gp,int v, int sv, int ev) {
    vector<int> ans;
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    unordered_map<int, int> mp;
    
    while( !q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < v; i++) {
            if(gp[front][i] && !visited[i]) {
                mp[i] = front;
                q.push(i);
                visited[i] = true;
                
                if(i == ev) {
                    int cur = ev;
                    ans.push_back(ev);
                    while( cur != sv) {
                        cur = mp[cur];
                        ans.push_back(cur);
                    }
                    return ans;
                }
            }
        }
    }
    
    return {}; // return NULL;
}

/*
vector<int> getPathBFS(vector<vector<bool>>& gp,int v, int sv, int ev) {
    vector<int> ans;
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    unordered_map<int, int> mp;
    bool fine = false;
    
    while( !q.empty() && !fine) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < v; i++) {
            if(gp[front][i] && !visited[i]) {
                mp[i] = front;
                q.push(i);
                visited[i] = true;
                
                if(i == ev) {
                    fine = true;
                    break;
                }
            }
        }
    }
    if( fine) {
        int cur = ev;
        ans.push_back(ev);
        while( cur != sv) {
            cur = mp[cur];
            ans.push_back(cur);
        }
        return ans;
    }
}
*/

int main() {
    
    int v, e;
    cin >> v >> e;
    vector<vector<bool>> graph(v, vector<bool>(v, false));
    
    for(int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        graph[f][s] = true;
        graph[s][f] = true;
    }
    
    int sv, ev;
    cin >> sv >> ev;
    
    vector<int> ans = getPathBFS(graph,v, sv, ev);
    for(auto i : ans) {
        cout << i << " ";
    }
	
    // No Need to deallocate memory , we created it statically;
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

vector<int> getPath(vector<vector<int>>& edges, int n, vector<bool>& visited, int s, int e) {
    vector<int> ans;
    if(s == e) {
        ans.push_back(e);
        return ans;
    }
    
    queue<int> q;
    unordered_map<int, int> map;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
       
        for(int i = 0; i < n; i++) {
            if(!visited[i] && edges[front][i]) {
                q.push(i);
            	map[i] = front;
                visited[i] = true;
                if(i == e) {
                    ans.push_back(e);
                    int x = e;
                    while(map[x] != s) {
                        ans.push_back(map[x]);
                        x = map[x];
                    }
                    ans.push_back(s);
                    return ans;
                }
            }
           
        }
    }
    return ans;
}

int main() {
	int n, e;
    cin >> n >> e;
    vector<vector<int>>edges(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    
    for(int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int a, b;
    cin >> a >> b;
    vector<int> ans = getPath(edges, n, visited, a, b);
    for(auto &i : ans) {
        cout << i << " ";
    }
    
}
*/