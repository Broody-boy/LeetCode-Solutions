class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> s;
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 0;
        
        for(int num : nums)
            s.insert(num);
        
        for(int num : s){
            
            if(s.find(num-1) != s.end()){   //smaller exists
                cnt++;
            }
            else{                           //smaller doesn't exist
                cnt = 1;
            }
            longest = max(longest, cnt);

        }

        return longest;
    }
};