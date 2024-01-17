class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        vector<int> arr(n);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            arr[i] = nums[i];
        }

        sort(nums.begin(), nums.end());

        while(left < right){
            if(nums[left] + nums[right] == target){

                for(int i = 0; i < n; i++){
                    if(arr[i] == nums[left]){
                        ans.push_back(i);
                        break;
                    }
                }

                for(int i = n-1; i >= 0; i--){
                    if(arr[i] == nums[right]){
                        ans.push_back(i);
                        break;
                    }
                }

                return ans;

            }
            else if(nums[left] + nums[right] < target)
                left++;
            else if(nums[left] + nums[right] > target)
                right--;
        }

        return {-1,-1};
    }
};