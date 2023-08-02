class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int checker=0;checker<=1;checker++)
            {
                int ans=-1;
                if(checker==1)
                {
                    ans=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else
                {
                    ans=max(prices[ind]+ dp[ind+2][1],dp[ind+1][0]);
                }
                dp[ind][checker]=ans;
            }
        }
        return dp[0][1];
    }
};