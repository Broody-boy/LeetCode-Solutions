class Solution {
public:

    int helper(int k){

        int prev2 = 1;
        int prev = 1;

        int curi;

        for(int i = 2; i <= k; i++){
            curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }

    int climbStairs(int n) {
        return helper(n);
    }
};