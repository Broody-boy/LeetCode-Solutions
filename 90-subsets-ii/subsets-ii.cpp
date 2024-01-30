class Solution {
public:

    void helper(int i, vector<int> v, set<vector<int>> &ans,vector<int> &nums){

        if(i == nums.size()){
            sort(v.begin(), v.end());
            ans.insert(v);
            return;
        }

        //pick:
        v.push_back(nums[i]);
        helper(i+1, v, ans, nums);

        //Not pick:
        v.pop_back();
        helper(i+1, v, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> v;

        helper(0, v, ans, nums);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};