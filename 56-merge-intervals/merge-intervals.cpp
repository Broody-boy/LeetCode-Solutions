class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        //Initialise with possibility of first pair being the merged pair:
        int startOfMerged = intervals[0][0];
        int endOfMerged = intervals[0][1];

        for(int i = 1; i < n; i++){
            int start = intervals[i][0];
            
            if(start <= endOfMerged){
                endOfMerged = max(endOfMerged, intervals[i][1]);
            } else{
                ans.push_back({startOfMerged, endOfMerged});
                startOfMerged = intervals[i][0];
                endOfMerged = intervals[i][1];
            }
        }

        //Finally, add the last merged pair:
        ans.push_back({startOfMerged, endOfMerged});

        return ans;
    }
};