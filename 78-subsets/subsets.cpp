class Solution {
public:

    void helper(int i, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums){

        if(i == nums.size()){
            ans.push_back(v);
            return;
        }

        //Pick
        v.push_back(nums[i]);
        helper(i + 1, v, ans, nums);
        
        //Not Pick
        v.pop_back();
        helper(i + 1, v, ans, nums);
    }


    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> v;
        helper(0, v, ans, nums);

        return ans;
    }
};