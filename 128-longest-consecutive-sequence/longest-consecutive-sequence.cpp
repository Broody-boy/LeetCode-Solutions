class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 0;

        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == lastSmaller + 1){
                cnt++;
                lastSmaller = nums[i];
                longest = max(longest, cnt);      //evaluate max at each step
            }
            else if(nums[i] > lastSmaller + 1){   //change of sequence
                lastSmaller = nums[i];
                cnt = 1;
            }
        }

        return (longest == 0) ? 1 : longest;
    }
};