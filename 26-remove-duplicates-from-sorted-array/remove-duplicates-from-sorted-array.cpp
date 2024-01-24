class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[pos]) continue;

            nums[pos+1] = nums[i];
            pos++;
        }

        return pos+1;
    }
};