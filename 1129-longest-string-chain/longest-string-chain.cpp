#include <bits/stdc++.h>
using namespace std;

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

class Solution {
public:

   bool compare(string& s1, string& s2){
        if(s2.size() != s1.size() + 1) return false;
        
        int first = 0;
        int second = 0;
        int pointOfDifference = 0;
        
        while(first < s1.size() && second < s2.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else {
                pointOfDifference++;
                second++;
            }
        }
        if(pointOfDifference == 0) return true;   //This handles the case when only the last character is different e.g abc and abca
        if(pointOfDifference == 1) return true;   //This means 1 point of difference, which is what we wanted
        return false; 
    }

    int longestStrChain(vector<string>& arr) {
        
        int n = arr.size();
        
        //sort the array
        sort(arr.begin(), arr.end(), comp);

        vector<int> dp(n,1);
        int maxi = 1;
        
        for(int i=0; i <= n-1; i++){            
            for(int prev = 0; prev < i; prev++){
                if(compare(arr[prev], arr[i]) && 1 + dp[prev] > dp[i]){
                    // cout << arr[i] << " ";
                    dp[i] = 1 + dp[prev];
                }
            }
            
            if(dp[i] > maxi) maxi = dp[i];
        }
        return maxi;
    }
};