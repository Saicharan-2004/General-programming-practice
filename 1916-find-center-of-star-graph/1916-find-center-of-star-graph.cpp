class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>tp;
        for(auto it:edges)
        {
            tp[it[0]]++;
            tp[it[1]]++;
        }
        int maxi = 0;
        int ans = 0;
        for(auto it:tp)
        {
            if(it.second>maxi)
            {
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};