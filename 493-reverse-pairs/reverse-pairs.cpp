class Solution {
public:

    int countPairs(vector<int> &nums, int low, int mid, int high){

        int right = mid+1;
        int ans = 0;

        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i] > (long long)2 * nums[right]) right++;
            ans+=(right-(mid+1));
        } //long long cast before 2 is important otherwise 2 * nums[right] is considered as integer

        return ans;
    }

    void merge(vector<int> &nums, int low, int mid, int high){

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while(left <= mid){
            temp.push_back(nums[left++]);
        }

        while(right <= high){
            temp.push_back(nums[right++]);
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }

    }

    int mergeSort(vector<int> &nums, int low, int high){
        
        if(low >= high) return 0;

        int mid = low + (high-low)/2;

        int countLeft = mergeSort(nums, low, mid);
        int countRight = mergeSort(nums, mid+1, high);
        int countCurr =  countPairs(nums, low, mid, high);     // Do this step before merge
        merge(nums, low, mid, high);

        return countLeft + countRight + countCurr;
    }

    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};