class Solution {
public:

    void helper(int ind, vector<int> &v, vector<vector<int>> &ans,vector<int> &nums){

        ans.push_back(v);

        for(int i = ind; i < nums.size(); i++){

            if(i != ind && nums[i] == nums[i-1]) continue;

            v.push_back(nums[i]);
            helper(i + 1, v, ans, nums);
            v.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> v;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        helper(0, v, ans, nums);

        return ans;

    }
};