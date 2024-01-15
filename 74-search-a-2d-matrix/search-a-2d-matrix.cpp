class Solution {
public:

    bool binarySearch(vector<int> arr, int target, int low, int high){
        
        if(low>high)
            return false;
        
        int mid = low + (high - low)/2;

        if(arr[mid] == target)
            return true;
        else if(arr[mid] > target)
            return binarySearch(arr, target, low, mid-1);
        else
            return binarySearch(arr, target, mid + 1, high);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> flat;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                flat.push_back(matrix[i][j]);
            }
        }

        return binarySearch(flat, target, 0, m*n-1);
    }
};