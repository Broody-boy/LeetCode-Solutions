class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;

        for(int i = 0; i < matrix.size(); i++){
            if(binary_search(matrix[i].begin(), matrix[i].end(), target)){
                flag = true;
                break;
            }
        }

        return flag;
    }
};