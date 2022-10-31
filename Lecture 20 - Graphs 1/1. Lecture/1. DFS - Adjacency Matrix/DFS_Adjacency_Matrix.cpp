#include<bits/stdc++.h>
using namespace std;

void print(int** edges, int n, int sv, bool* vis) {
	cout << sv << " ";
	vis[sv] = true;
	for (int i = 0; i < n; i++) {
		if (i == sv) continue;

		if (edges[sv][i] == 1) {
			if (!vis[i]) print(edges, n, i, vis);
		}
	}
}

void printBFS(int** edges, int n, int sv) {

	queue<int> q;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	q.push(sv);
	visited[sv] = true;

	while (!q.empty()) {
		int curvertex = q.front();
		q.pop();
		cout << curvertex << " ";


		for (int i = 0; i < n; i++) {
			if (i == curvertex) continue;

			if (edges[curvertex][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif

	int n;
	int e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f , s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	bool* vis = new bool[n];
	for (int i = 0; i < n; i++) vis[i] = false;

	print(edges, n, 0, vis);
	cout << endl;
	// printBFS(edges, n, 0) ;


	delete [] vis;
	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;

	return 0;
}

/*
7
8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
5 6

0 1 3 5 4 6 2
*/