#include<bits/stdc++.h>
using namespace std;


int f(vector<vector<int>> &cake, int n, int i, int j, vector<vector<bool>>& vis) {
    vis[i][j] = true;
    int sum = 1;

    if(i+1 < n && !vis[i+1][j] && cake[i+1][j] == 1) {
        // vis[i+1][j] = true;
       sum += f(cake, n, i+1, j, vis);
    }

    if(i-1 >=0 && !vis[i-1][j] && cake[i-1][j] == 1) {
        // vis[i-1][j] = true;
        sum += f(cake, n, i-1, j, vis);
    }
    
    if(j-1 >=0 && !vis[i][j-1] && cake[i][j-1] == 1) {
        // vis[i][j-1] = true;
        sum += f(cake, n, i, j-1, vis);
    }

    if(j+1 < n && !vis[i][j+1] && cake[i][j+1] == 1) {
        // vis[i][j+1] = true;
        sum += f(cake, n, i, j+1, vis);
    }

    return sum;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
	int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cake[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = true;
                int maxSum = f(cake, n, i, j, visited);
                count = max(maxSum, count);
            }
        }
    }
    return count;
}