class Solution {
public:

    void helper(int i, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums){

        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(target < 0 || i == nums.size()) return;

        //pick:
        v.push_back(nums[i]);
        helper(i, target-nums[i], v, ans, nums);

        //Not pick:
        v.pop_back();
        helper(i + 1, target, v, ans, nums);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        helper(0, target, v, ans, candidates);

        return ans;
    }
};