class Solution {
public:
    int helper(int ind,vector<int>coins,int target,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            return target%coins[0]==0;
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        int notTake=helper(ind-1,coins,target,dp);
        int take=0;
        if(target>=coins[ind])
        {
            take=helper(ind,coins,target-coins[ind],dp);
        }
        return dp[ind][target]=take+notTake;
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++)
        {
            dp[0][target]=(target%coins[0]==0);
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake=dp[ind-1][target];
                int take=0;
                if(target>=coins[ind])
                {
                    take=dp[ind][target-coins[ind]];
                }
                dp[ind][target]=take+nottake;
            }
        }
        return dp[coins.size()-1][amount];
    }
};