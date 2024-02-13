class Solution {
public:

    int helper(int i, vector<int> &nums, vector<int> &dp){

        if(i==0) return nums[0];
        if(i==1) return max(nums[1], nums[0]);

        if(dp[i] != -1) return dp[i];

        //Pick
        int pick = nums[i] + helper(i-2, nums, dp);

        //Not Pick
        int notPick = helper(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n-1, nums, dp);
    }
};