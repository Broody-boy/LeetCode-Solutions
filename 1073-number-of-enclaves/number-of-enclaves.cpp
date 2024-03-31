class Solution {

public:

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid){

        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i > m-1 || j < 0 || j > n-1 || vis[i][j]) return;
        vis[i][j] = true;

        if(grid[i][j] == 1){
            dfs(i+1, j, vis, grid);
            dfs(i, j+1, vis, grid);
            dfs(i-1, j, vis, grid);
            dfs(i, j-1, vis, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
         
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        //left right:
        for(int row = 0; row < m; row++){
            //if(mat[row][0] == 'O' && !vis[row][0])        //no need of this as dfs function can handle it
            dfs(row, 0, vis, grid);
            //if(mat[row][n-1] == 'O' && !vis[row][n-1])    //no need of this as dfs function can handle it
            dfs(row, n-1, vis, grid);
        }

        //top bottom:
        for(int col = 0; col < n; col++){
            //if(mat[0][col] == 'O' && !vis[0][col])        //no need of this as dfs function can handle it
            dfs(0, col, vis, grid);
            //if(mat[m-1][col] == 'O' && !vis[m-1][col])    //no need of this as dfs function can handle it
            dfs(m-1, col, vis, grid);
        }

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) count++;
            }
        }

        return count;
    }
};