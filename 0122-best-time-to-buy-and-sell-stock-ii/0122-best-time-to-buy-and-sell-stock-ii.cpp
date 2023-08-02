class Solution {
public:
    int helper(vector<int>prices,int ind,int checker,vector<vector<int>>&dp)
    {
        if(ind==prices.size())
        {
            return 0;
        }
        if(dp[ind][checker]!=-1)
        {
            return dp[ind][checker];
        }
        int ans=-1;
        if(checker==1)
        {
            ans=max(-prices[ind]+helper(prices,ind+1,0,dp),  helper(prices,ind+1,1,dp));
        }
        else
        {
            ans=max(prices[ind]+helper(prices,ind+1,1,dp), helper(prices,ind+1,0,dp));
        }
        return dp[ind][checker]= ans;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>curr(2,0),forw(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int checker=0;checker<=1;checker++)
            {
                int ans=-1;
                if(checker==1)
                {
                    ans=max(-prices[ind]+forw[0],forw[1]);
                }
                else
                {
                    ans=max(prices[ind]+forw[1],forw[0]);
                }
                curr[checker]=ans;
            }
            forw=curr;
        }
        return curr[1];
    }
};