class Solution {
public:

    void bfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        queue<pair<int, int>> q;

        q.push({i, j});
        vis[i][j] = true;

        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for(auto delta: directions){
                int newI = node.first + delta.first;
                int newJ = node.second + delta.second;

                if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == '1' && !vis[newI][newJ]){
                    q.push({newI, newJ});
                    vis[newI][newJ] = true;
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {

        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        int island = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i, j, vis, grid);
                    island++;
                }
            }
        }

        return island;
    }
};