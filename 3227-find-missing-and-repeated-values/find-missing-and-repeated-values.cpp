class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int, int> m;

        int n = grid.size();
        long long sum = 0;
        int repeated = -1;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                sum += grid[i][j];

                if (m[grid[i][j]] == 0)
                    m[grid[i][j]]++;
                else{
                    repeated = grid[i][j];
                    ans.push_back(repeated);
                }

            }

        }

        //We have found the repeated element. Now find missing:
        long long normalSum = (n*n) * (n*n + 1) / 2;    // sum = n*(n + 1)/2

        int missing = normalSum - (sum - repeated);

        ans.push_back(missing);

        return ans;
    }
};