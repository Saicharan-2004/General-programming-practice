class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int i = 0;
        int n = intervals.size();
        while(i<n)
        {
            // int start = intervals[i][0];
            if(ans.size() == 0 || ans.back()[1]<intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            i++;
        }
        return ans;
    }
};