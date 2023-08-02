class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int>ans(nums.begin(),nums.end());
        for(auto it:nums)
        {
            ans.push_back(it);
        }
        return ans;
    }
};