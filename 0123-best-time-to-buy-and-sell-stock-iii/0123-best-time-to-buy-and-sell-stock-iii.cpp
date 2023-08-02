class Solution {
public:
    int helper(vector<int>prices,int ind,int trans,int checker,vector<vector<vector<int>>>&dp)
    {
        if(ind==prices.size()||trans==0)
        {
            return 0;
        }
        if(dp[ind][checker][trans]!=-1)
        {
            return dp[ind][checker][trans];
        }
        int ans=-1;
        if(checker==1&&trans>=0)
        {
            ans=max(-prices[ind]+helper(prices,ind+1,trans,0,dp),helper(prices,ind+1,trans,1,dp));
        }
        else
        {
            ans=max(prices[ind]+helper(prices,ind+1,trans-1,1,dp), helper(prices,ind+1,trans,0,dp));
        }
        return dp[ind][checker][trans]= ans;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>curr(2,vector<int>(3,0)),forw(2,vector<int>(3,0));
        vector<int>currbuy(3,0);
        vector<int>currnotbuy(3,0);
        vector<int>forwbuy(3,0);
        vector<int>forwnotbuy(3,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=1;trans<=2;trans++)
            {
                currbuy[trans]=max(-prices[ind]+forwnotbuy[trans],forwbuy[trans]);
                currnotbuy[trans]=max(prices[ind]+forwbuy[trans-1], forwnotbuy[trans]);
            }
            forwbuy=currbuy;
            forwnotbuy=currnotbuy;
        }
        return currbuy[2];
    }
};