class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        vector<int> ans(2);
        unordered_map<int, int> m;

        int n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[grid[i][j]]++;
            }
        }

        for(int i = 1; i <= n * n; i++){

            (m[i] == 2)
                ? ans[0] = i
            : (m[i] == 0) 
                ? ans[1] = i
            : 0;
        }

        return ans;

    }
};