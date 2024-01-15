class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){

            if(target >= matrix[i][0]  && target <= matrix[i][n-1]){
                return binary_search(matrix[i].begin(), matrix[i].end(), target);
            }

        }

        return false;
    }
};