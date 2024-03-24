class Solution {
public:

    int nCr(int n, int r){

        if (r > n) return 0; //safeguard

        if(r > n-r) r = n-r; //choose small value of r for optimisation

        double ans = 1.0;
        for(int i = 1; i <= r; i++){
            ans = ans * (n-r+i)/i;
        }
        return (int)ans;
    }

    int uniquePaths(int m, int n) {
        return nCr(m+n-2, n-1);
    }

};