// class Solution {
// public:
//     int findSmallest(int num,vector<pair<vector<int>,int>>tp)
//     {
//         int start = 0;
//         int end = tp.size()-1;
//         while(start<=end)
//         {
//             int mid = start + (end-start)/2;
//             if(tp[mid].first[0] < num)
//             {
//                 start = mid + 1;
//             }
//             else
//             {
//                 end = mid - 1;
//             }
//         }
//         return start == tp.size() ? -1 : tp[start].second;
//     }
//     vector<int> findRightInterval(vector<vector<int>>& intervals) {
//         vector<pair<vector<int>,int>>tp;
//         int n = intervals.size();
//         for(int i = 0;i<n;i++)
//         {
//             tp.push_back({{intervals[i][0],intervals[i][1]},i});
//         }
//         sort(tp.begin(),tp.end());
//         vector<int>ans;
//         for(auto it:intervals)
//         {
//             int start = findSmallest(it[1],tp);
//             ans.push_back(start);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for(int i = 0; i < intervals.size(); i++) 
               ans[i]  = m.lower_bound(intervals[i][1])!=end(m)?m.lower_bound(intervals[i][1]) -> second:-1;
        return ans;
    }
};
