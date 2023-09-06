class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>temp;
        for(auto it:nums)
        {
            temp[it]++;
        }
        priority_queue<pair<int,int>>templ;
        for(auto it:temp)
        {
            templ.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(templ.top().second);
            templ.pop();
        }
        return ans;
    }
};