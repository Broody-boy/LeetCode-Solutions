#include <vector>
#include <queue>
using namespace std;

class Solution {

private:
    vector<pair<int, int>> returnNextRound(vector<pair<int, int>> currRotten, int &fresh, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> nextRotten;
        for(auto coordinate: currRotten){
            int i = coordinate.first;
            int j = coordinate.second;

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dir : directions) {
                int x = i + dir.first;
                int y = j + dir.second;

                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    nextRotten.push_back({x, y});
                    fresh--;
                }
            }
        }
        return nextRotten;

    }

public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int, int>> currRotten;

        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    currRotten.push_back({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0) return 0; // No fresh oranges to rot
        
        int ans = 0;

        while (!currRotten.empty()) {
            vector<pair<int, int>> nextRotten = returnNextRound(currRotten, fresh, grid);
            if(!nextRotten.empty()) ans++;
            currRotten = nextRotten;
        }

        return fresh == 0 ? ans : -1; // If there are still fresh oranges left, return -1
    }
};
