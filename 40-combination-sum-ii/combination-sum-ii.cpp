class Solution {
public:

    void helper(int ind, int target, vector<int> &v, vector<vector<int>> &ans, vector<int>& nums){

        if(target == 0) {
            ans.push_back(v);
            return;
        }

        for(int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) break;
            v.push_back(nums[i]);
            helper(i + 1, target - nums[i], v, ans, nums);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <vector<int>> ans;
        vector<int> v;

        sort(candidates.begin(),candidates.end());
        helper(0, target, v, ans, candidates);

        return vector<vector<int>>(ans.begin(), ans.end());
    }

};