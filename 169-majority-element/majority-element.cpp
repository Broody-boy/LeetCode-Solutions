//Case 1: If Count is 0 then store the current element of the array as Element.
//Case 2: If the current element and Element are the same increase the Count by 1.
//Case 3: If they are different decrease the Count by 1.

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int element = -1;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0)
                element = nums[i];

            if(nums[i] == element)  //case 1 and 2 are both covered by this
                count ++;
            else
                count--;
        }

        return element;

    }
};