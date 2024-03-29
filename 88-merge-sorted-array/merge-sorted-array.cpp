class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int j = n-1;
        int target = m + n - 1;

        while(i >= 0 && j >= 0){

            if(nums1[i] >= nums2[j])
                nums1[target--] = nums1[i--];
            else
                nums1[target--] = nums2[j--];
        }

        while(j >= 0){
                nums1[target--] = nums2[j--];
        }

        // Note: No need of iterating over nums1 as it will be already in its place
        // So, the following loop is not necessary:
        // while(i >= 0){
        //     nums1[target--] = nums1[i--];
        //     nums1[target--] = nums1[j--];
        // }

    }
};