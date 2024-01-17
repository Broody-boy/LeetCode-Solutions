class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        int longest = 0;
        unordered_set<int> s;
        
        for(int num : nums)
            s.insert(num);

        for(int i = 0; i < nums.size(); i++){

            if(s.find(nums[i]-1) == s.end()){  //Do processing only for starting elements

                //find sequence length using the varibale count:
                int next = nums[i] + 1;
                int count = 1;                  //count = 1 beacuse of the starting element.
                while(s.find(next) != s.end()){
                    next = next + 1;
                    count++;
                }
                //sequence length found. Now update global:

                longest = max(longest, count);
            }
        }

        return longest;
    }
};