class Solution {
public:

    void helper(vector<int>& v, vector<int>& freq, vector<int>& nums, vector<vector<int>>& ans){
        
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }


        for(int i = 0; i < nums.size(); i++){
            if(freq[i] == 0){       //index not already taken

                v.push_back(nums[i]);
                freq[i] = 1;

                helper(v, freq, nums, ans);

                v.pop_back();
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> freq(nums.size(), 0);

        helper(v, freq, nums, ans);

        return ans;
    }
};