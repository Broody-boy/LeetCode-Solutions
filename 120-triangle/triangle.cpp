class Solution {
public:

    void helper(int n, vector<vector<int>>& triangle, vector<int>& previous, vector<int>& current){

        for(int col = 0; col < n; col++)
            previous[col] = triangle[n-1][col];

        for(int row = n-2; row >= 0; row--){
            for(int col = row; col >= 0; col--){
                int d = triangle[row][col] + previous[col];
                int dr = triangle[row][col] + previous[col+1];
                current[col] = min(d, dr);
            }
            previous = current;
        }
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int>previous(n, 0);
        vector<int>current(n, 0);
        helper(n, triangle, previous, current);
        return previous[0];
    }
};