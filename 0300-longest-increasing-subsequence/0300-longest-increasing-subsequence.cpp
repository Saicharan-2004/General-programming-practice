class Solution {
public:
    int helper(vector<int>nums,int ind,int prev,int n,vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }
        int nottake=helper(nums,ind+1,prev,n,dp);
        int take=0;
        if(prev==-1||nums[ind]>nums[prev])
        {
            take=1+helper(nums,ind+1,ind,n,dp);
        }
        return dp[ind][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=n-1;prev>=-1;prev--)
            {
                int ans=0;
                ans=dp[ind+1][prev+1];
                if(prev==-1||nums[ind]>nums[prev])
                {
                    ans=max(ans,1+dp[ind+1][ind+1]);
                }
                dp[ind][prev+1]=ans;
            }
        }
        return dp[0][0];
    }
};