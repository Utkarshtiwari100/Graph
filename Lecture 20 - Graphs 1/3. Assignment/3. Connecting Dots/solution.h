bool findcycle = false;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
void dfs(int x, int y, int fromX, int fromY, char needColor,int n, int m,vector<vector<char>> &board,vector<vector<bool>> &visited)
{
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(board[x][y] != needColor) return;
	if(visited[x][y])
	{
		findcycle = true;
		return;
	}
	visited[x][y] = true;
	for(int f = 0; f < 4; f++)
	{
		int nextX = x + dx[f];
		int nextY = y + dy[f];
		if(nextX == fromX && nextY == fromY) continue;
		dfs(nextX, nextY, x, y, needColor,n,m,board,visited);
	}
}
bool hasCycle(vector<vector<char>> &board,int n, int m)   
{
    	vector<vector<bool>> visited(n,vector<bool>(m,false));
		for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				dfs(i, j, -1, -1, board[i][j],n,m,board,visited);
            }
        }
    }

	return findcycle;
}