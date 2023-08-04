class Solution {
public:
    int mod=1e9+7;
    int helper(int ind,vector<int>&dp)
    {
        if(ind<0)
        {
            return 0;
        }
        if(ind==1)
        {
            return 1;
        }
        if(ind==2)
        {
            return 2;
        }
        if(ind==3)
        {
            return 5;
        }
        if(ind==4)
        {
            return 11;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind]%mod;
        }
        int takeone=helper(ind-1,dp)%mod;
        int takeThree=helper(ind-3,dp)%mod;
        return dp[ind]= ((2*takeone)%mod+takeThree)%mod;
    }
    int numTilings(int n) 
    {
        vector<int>dp(n+1,-1);
        return helper(n,dp)%mod;
    }
};