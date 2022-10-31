#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& edges, int n, int sv, vector<bool>& visited) {
    queue<int> q;

    for (int i = 0 ; i < n ; i ++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curvertex = q.front();
                q.pop();
                cout << curvertex << " ";

                for (int i = 0; i < n; i++) {
                    if (i == curvertex) continue;

                    if (!visited[i] && edges[curvertex][i] == 1) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }

    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("iput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int v, e;
    cin >> v >> e;

    vector<vector<int> >edges (v , vector<int>(v , 0));

    for (int i = 0 ; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    vector<bool> visited(v, false);

    print(edges, v, 0, visited);
}