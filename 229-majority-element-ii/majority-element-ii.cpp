class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int el1 = INT_MIN, el2 = INT_MIN, cnt1= 0, cnt2 = 0;
        int targetCount = nums.size()/3 + 1;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){   
            if(cnt1 == 0 && nums[i] != el2){
                el1 = nums[i];
                cnt1 = 1;
            } else if(cnt2 == 0 && nums[i] != el1){
                el2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }


        int count1 = 0, count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el1) count1++;
            if(nums[i] == el2) count2++;
        }

        if(count1 >= targetCount) ans.push_back(el1);
        if(count2 >= targetCount) ans.push_back(el2);

        return ans;
    }
};