#include <bits/stdc++.h>
using namespace std;

int countCycle(vector<vector<int>>& g, int n) {
    int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && g[i][j]==1)
			{
				for (int k = 0; k < n; k++)
				{
					if (j != k && k != i && g[j][k]==1)
					{
						if (g[i][k] == 1)
						{
							count += 1;
						}
					}
				}
			}
		}
	}
	return count;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> g(v, vector<int>(v, 0));
    
    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    
    cout << countCycle(g, v)/6;
}