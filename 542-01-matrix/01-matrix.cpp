class Solution {
public:

    vector<vector<int>> returnNextRound(vector<vector<int>> currLot, int currCount, vector<vector<bool>> &vis, vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> nextLot;
        for(auto coordinate: currLot){
            int i = coordinate[0];
            int j = coordinate[1];

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dir : directions) {
                int newI = i + dir.first;
                int newJ = j + dir.second;

                if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && !vis[newI][newJ] && mat[newI][newJ] == 1) {
                    vis[newI][newJ] = true;
                    mat[newI][newJ] = currCount+1;
                    nextLot.push_back({newI, newJ, currCount+1});
                }
            }
        }
        return nextLot;

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> currLot;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0){
                    currLot.push_back({i, j, 0});
                }
            }
        }

        int currRound = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        while(!currLot.empty()) {
            vector<vector<int>> nextLot = returnNextRound(currLot, currRound, vis, mat);
            if(!nextLot.empty()) currRound++;
            currLot = nextLot;  // For the next round, nextLot will become its currRotten.
        }

        return mat;
    }
};