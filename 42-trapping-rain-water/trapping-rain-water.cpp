class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        vector<int> left(n);
        vector<int> right(n);

        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;

        int trappedWater = 0;

        for(int i = 0; i < n; i++){
            maxLeft = max(maxLeft, height[i]);
            left[i] = maxLeft;
        }

        for(int i = n-1; i >= 0; i--){
            maxRight = max(maxRight, height[i]);
            right[i] = maxRight;
        }

        for (int i = 0; i < n; i++) {
            int minHeight = min(left[i], right[i]);
            trappedWater += minHeight - height[i];
        }

        return trappedWater;
    }
};