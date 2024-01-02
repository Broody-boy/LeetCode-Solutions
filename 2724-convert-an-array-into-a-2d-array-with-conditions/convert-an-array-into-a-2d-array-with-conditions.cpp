class Solution {
public:

    bool isExists(int key, vector<int> target){
        
        bool isFound = false;

        for(auto num: target)
            if(num == key) return true;

        return isFound;
    }

    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;

        for(auto num : nums){

            bool wasPlaced = false;
            
            for(int row = 0; row < ans.size(); row++){
                if(!isExists(num, ans[row])){
                    ans[row].push_back(num);
                    wasPlaced = true;
                    break;
                }
            }

            if(!wasPlaced){
                vector<int> newRow = {num};
                ans.push_back(newRow);
            }

        }

        return ans;
    }
};