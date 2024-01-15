class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int element = -1;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0)
                element = nums[i];

            if(nums[i] == element)  //case 1 and 2 are already covered
                count ++;
            else
                count--;
        }

        return element;

    }
};