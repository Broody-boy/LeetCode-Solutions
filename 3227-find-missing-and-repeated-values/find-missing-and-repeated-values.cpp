class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();
        long long n2 = (long long)n * (long long)n;


        long long sum = 0;
        long long squareSum = 0;

        long long nSum = (n2) * (n2 + 1) / 2;
        long long nSquareSum = n2 * (n2 + 1) * (2*n2 + 1)/ 6;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
                squareSum += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }

        long long Diff = sum - nSum;
        long long Sum = (squareSum - nSquareSum)/Diff;

        int x = (Sum + Diff) / 2;
        int y = (Sum - Diff) / 2;

        return {x,y};
    }
};