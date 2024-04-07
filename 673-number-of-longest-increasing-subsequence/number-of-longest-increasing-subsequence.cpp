class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
        vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    // Inherit count
                    ct[i] = ct[prev];
                } else if(nums[prev] < nums[i] && 1+dp[prev] == dp[i]){
                     // Increase the count
                    ct[i] = ct[i] + ct[prev];
                }
            }
        }

        int maxi = *max_element(dp.begin(), dp.end());

        int ans = 0;
        //Count occurences of maxi in the dp array:
        for(int i = 0; i < n; i++) if(dp[i]==maxi) ans+=ct[i];

        return ans;
    }
};