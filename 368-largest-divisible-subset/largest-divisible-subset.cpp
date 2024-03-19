class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i < n; i++) hash[i] = i;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(arr[i] % arr[prev] == 0 && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }

        vector<int> ans;
        int ind = max_element(dp.begin(), dp.end()) - dp.begin();
        while(hash[ind] != ind){
            ans.push_back(arr[ind]);
            ind = hash[ind];
        }
        ans.push_back(arr[ind]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};