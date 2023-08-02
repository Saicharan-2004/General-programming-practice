class Solution {
public:
    int helper(int tar,int ind,vector<vector<int>>&dp)
    {
        if(tar==0)
        {
            return 0;
        }
        if(ind*ind>tar)
        {
            return 1e8;
        }      
        if(dp[ind][tar]!=-1)
        {
            return dp[ind][tar];
        }
        int nottake=helper(tar,ind+1,dp);
        int take=INT_MAX;
        if(tar>=pow(ind,2))
        {
            take=1+helper(tar-pow(ind,2),ind,dp);
        }
        return dp[ind][tar]= min(take,nottake);
    }
    int numSquares(int n) 
    {
        vector<int>dp(n+2,1e9);
        dp[0]=0;
        for(int tar=1;tar<=n;tar++)
        {
            for(int ind=1;ind*ind<=tar;ind++)
            {
                dp[tar]=min(dp[tar],1+dp[tar-ind*ind]);
            }
        }
        return dp[n];
    }
};