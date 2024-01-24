class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
       unordered_map <char, int> mp;

       int l = 0;
       int r = 0;
       int ans = 0;

       while(r < s.length()){
           if(mp.find(s[r]) != mp.end() && l <= mp[s[r]]){
               l = mp[s[r]] + 1;
           }
           else {
                ans = max(ans, r-l + 1);
                mp[s[r]] = r;
                r++;
           }
       }

        return ans;
    }
};