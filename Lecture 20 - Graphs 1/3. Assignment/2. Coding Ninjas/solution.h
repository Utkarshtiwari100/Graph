/*

Coding Ninjas

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1

*/

#include<bits/stdc++.h>

bool bfs(vector<vector<char>> &board,vector<vector<bool>>& visited, int n, int m, int i, int j, string str) {
    
    if(str.size() == 0) {
        return true;
    }
    visited[i][j] = true;
    
    bool ans = false;
    //Down
    if( i + 1 < n && !visited[i+1][j] && board[i+1][j] == str[0] ) {
        if(bfs(board, visited, n, m, i+1, j, str.substr(1))) {
            return true;
        }
    }
    
    //Up
    if( i-1 >=0 && !visited[i-1][j] && board[i-1][j] == str[0]) {
        if(bfs(board, visited, n, m, i-1, j, str.substr(1))) {
            return true;
        }
    }
    
    //Left
    if( j-1 >=0 && !visited[i][j-1] && board[i][j-1] == str[0]) {
        if(bfs(board, visited, n, m, i, j-1, str.substr(1))) {
            return true;
        }
    }
    
    //Right
    if( j+1 < m && !visited[i][j+1] && board[i][j+1] == str[0] ) {
        if(bfs(board, visited, n, m, i, j+1, str.substr(1))) {
            return true;
        }
    }
    
    //Down Left
    if( i+1 < n && j-1 >= 0 && !visited[i+1][j-1] && board[i+1][j-1] == str[0]) {
        if(bfs(board, visited, n, m, i+1, j-1, str.substr(1))) {
            return true;
        }
    }
    
    //Down Right
    if( i+1 < n && j+1 < m && !visited[i+1][j+1] && board[i+1][j+1] == str[0]) {
        if(bfs(board, visited, n, m, i+1, j+1, str.substr(1))) {
            return true;
        }
    }
    
    //Up Left
    if( i-1 >=0 && j-1 >=0 && !visited[i-1][j-1] && board[i-1][j-1] == str[0]) {
        if(bfs(board, visited, n, m, i-1, j-1, str.substr(1))) {
            return true;
        }
    }
           
    //Up Right
    if(i-1 >= 0 && j+1 < m && !visited[i-1][j+1] && board[i-1][j+1] == str[0]) {
        if( bfs(board, visited, n, m, i-1, j+1, str.substr(1))) {
            return true;
        }
    }
           
	visited[i][j] = false;
    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
           if(board[i][j] == 'C') {
                string str = "ODINGNINJA";
                if(bfs(board, visited, n, m, i, j, str)) {
                    return true;
                }
           }
        }
    }
    return false;
}