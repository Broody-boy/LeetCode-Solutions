class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int, int> mp;
        int targetCount = nums.size()/3 + 1;
        vector<int> ans;

        for(int num : nums){

            mp[num]++;

            if(mp[num] == targetCount)
                ans.push_back(num);

        }

        return ans;
    }
};