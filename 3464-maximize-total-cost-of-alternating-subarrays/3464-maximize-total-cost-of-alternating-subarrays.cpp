class Solution {
public:
    long long int helper(vector<int>nums,int ind,int pehalese,vector<vector<long long int>>&dp)
    {
        if(ind == nums.size())    return 0;
        if(dp[ind][pehalese]!= -1)
        {
            return dp[ind][pehalese];
        }
        if(pehalese)
        {
            return dp[ind][pehalese] = max(nums[ind] + helper(nums,ind+1,1,dp),-nums[ind] + helper(nums,ind+1,0,dp));
        }
        else
        {
            return dp[ind][pehalese] = nums[ind] + helper(nums,ind+1,1,dp);
        }
    }
    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long int>>dp(nums.size() + 2,vector<long long int>(2,0));
        // bool pehalse = false;
        int n = nums.size();
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int pehalese = 1;pehalese>=0;pehalese--)
            {
                if(pehalese)
                {
                    dp[ind][pehalese] = max(nums[ind] + dp[ind+1][1],-nums[ind] + dp[ind+1][0]);
                }
                else
                {
                    dp[ind][pehalese] = nums[ind] + dp[ind+1][1];
                }
            }
        }
        return dp[0][0];
    }
};