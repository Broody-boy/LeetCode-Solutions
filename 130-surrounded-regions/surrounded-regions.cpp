class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& board){
        
        int m = board.size();
        int n = board[0].size();
        
        if(i < 0 || i > m-1 || j < 0 || j > n-1 || vis[i][j]) return;
        vis[i][j] = true;

        if(board[i][j] == 'O'){
            dfs(i+1, j, vis, board);
            dfs(i, j+1, vis, board);
            dfs(i-1, j, vis, board);
            dfs(i, j-1, vis, board);
        } //else-> return as it is;

    }

    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        //left right:
        for(int row = 0; row < m; row++){
            //if(mat[row][0] == 'O' && !vis[row][0])        //no need of this as dfs function can handle it
            dfs(row, 0, vis, board);
            //if(mat[row][n-1] == 'O' && !vis[row][n-1])    //no need of this as dfs function can handle it
            dfs(row, n-1, vis, board);
        }

        //top bottom:
        for(int col = 0; col < n; col++){
            //if(mat[0][col] == 'O' && !vis[0][col])        //no need of this as dfs function can handle it
            dfs(0, col, vis, board);
            //if(mat[m-1][col] == 'O' && !vis[m-1][col])    //no need of this as dfs function can handle it
            dfs(m-1, col, vis, board);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }

    }
};