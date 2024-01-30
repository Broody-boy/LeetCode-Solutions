class Solution {
public:

    void helper(int i, vector<int> &v, vector<vector<int>>& ans, int n){

        if(i == n){
            ans.push_back(v);
            return;
        }


        for(int j = i; j < n; j++){
            swap(v[i], v[j]);
            helper(i+1, v, ans, n);
            swap(v[i], v[j]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int> v(nums.begin(), nums.end());
        int n = nums.size();

        helper(0, v, ans, n);

        return ans;
    }
};