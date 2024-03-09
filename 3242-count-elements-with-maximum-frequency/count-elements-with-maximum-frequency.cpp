class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int>temp;
        int maxi=INT_MIN;
        for(auto it:nums)
        {
            temp[it]++;
            maxi=max(maxi,temp[it]);
        }
        int ans=0;
        for(auto it:temp)
        {
            if(it.second==maxi)
            {
                ans+=maxi;
            }
        }
        return ans;
    }
};