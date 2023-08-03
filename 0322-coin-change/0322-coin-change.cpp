class Solution {
public:
    int helper(vector<int>coins,int ind,int target,vector<vector<int>>&dp)
	{
	    if(ind==0)
	    {
	        if(target%coins[ind]==0)
	        {
	            return target/coins[ind];
	        }
	        else
	        {
	            return 1e9;
	        }
	    }
	    if(dp[ind][target]!=-1)
	    {
	        return dp[ind][target];
	    }
	    int notTake=helper(coins,ind-1,target,dp);
	    int take=INT_MAX;
	    if(target>=coins[ind])
	    {
	        take=1+helper(coins,ind,target-coins[ind],dp);
	    }
	    return dp[ind][target]=min(take,notTake);
	}
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        // int help=helper(coins,coins.size()-1,amount,dp);
        // if(help>=1e9)
        // {
        //     return -1;
        // }
        // return help;
        for(int tar=0;tar<=amount;tar++)
        {
            if(tar%coins[0]==0)
            {
                dp[0][tar]=tar/coins[0];
            }
            else
            {
                dp[0][tar]=1e9;
            }
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notTake=dp[ind-1][target];
                int take=INT_MAX;
                if(coins[ind]<=target)
                {
                    take=1+dp[ind][target-coins[ind]];
                }
                dp[ind][target]=min(notTake,take);
            }
        }
        int n=coins.size();
        int help=dp[n-1][amount];
        if(help>=1e9)
        {
            return -1;
        }
        return help;
    }
};