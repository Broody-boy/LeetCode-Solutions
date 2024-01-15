class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;
        long long nn = n;
        if(n < 0) nn = -nn;

        while(nn){
            if(nn%2){
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x*x;
                nn = nn/2;
            }
        }

        return (n < 0) ? (double) 1.0 / (double) ans : ans;

    }
};