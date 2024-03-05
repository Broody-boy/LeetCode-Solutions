class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();

        if(i < 0 || j < 0 || i > m-1 || j > n-1 || vis[i][j] || board[i][j] == 'X') return;
        vis[i][j] = 1;

        dfs(i+1, j, board, vis);
        dfs(i-1, j, board, vis);
        dfs(i, j+1, board, vis);
        dfs(i, j-1, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int col = 0; col < n; col++){
            if(!vis[0][col] && board[0][col] == 'O') dfs(0, col, board, vis);            
            if(!vis[m-1][col] && board[m-1][col] == 'O') dfs(m-1, col, board, vis);
        }

        for(int row = 0; row < m; row++){
            if(!vis[row][0] && board[row][0] == 'O') dfs(row, 0, board, vis);
            if(!vis[row][n-1] && board[row][n-1] == 'O') dfs(row, n-1, board, vis);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};