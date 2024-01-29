class Solution {
public:

    void helper(int i, vector<int>& v, unordered_map<int,int>& mp , vector<int>& nums, vector<vector<int>>& ans){
        
        if(i == nums.size()){
            ans.push_back(v);
            return;
        }


        for(int num : nums){
            if(mp[num] == 0){       //num not already taken

                v.push_back(num);
                mp[num] = 1;

                helper(i + 1, v, mp, nums, ans);

                v.pop_back();
                mp[num] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> mp;

        helper(0, v, mp, nums, ans);

        return ans;
    }
};