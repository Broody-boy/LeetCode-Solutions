class Solution {
public:

    void helper(int ind, string &v, int &counter, vector<int> &freq, string &ans, string &nums){

        if(ind == nums.size()){
            counter--;
            if(counter == 0){
                ans = v;
            }
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(freq[i] == 0){

                freq[i] = 1;
                v.push_back(nums[i]);

                helper(ind + 1, v, counter, freq, ans, nums);

                v.pop_back();
                freq[i] = 0;
            }
        }
    }

    string getPermutation(int n, int k) {

        string nums;
        for(int num = 1; num <= n; num++) nums.push_back(num + '0');

        string ans;
        string v;

        vector<int> freq(n, 0);

        helper(0, v, k, freq, ans, nums);
        return ans;
    }
};