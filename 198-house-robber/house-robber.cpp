class Solution {
public:

    void helper(int n, vector<int> &nums, vector<int> &dp){

        dp[0] = nums[0];
        if(n >=1 ) dp[1] = max(nums[1], nums[0]);

        for(int i = 2; i <= n; i++){
            int pick = nums[i] + dp[i-2];
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        helper(n-1, nums, dp);
        return dp[n-1];
    }
};