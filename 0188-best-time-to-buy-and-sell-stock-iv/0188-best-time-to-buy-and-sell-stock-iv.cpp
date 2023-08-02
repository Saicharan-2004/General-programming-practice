class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // vector<vector<int>>curr(2,vector<int>(3,0)),forw(2,vector<int>(3,0));
        vector<int>currbuy(k+1,0);
        vector<int>currnotbuy(k+1,0);
        vector<int>forwbuy(k+1,0);
        vector<int>forwnotbuy(k+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=1;trans<=k;trans++)
            {
                currbuy[trans]=max(-prices[ind]+forwnotbuy[trans],forwbuy[trans]);
                currnotbuy[trans]=max(prices[ind]+forwbuy[trans-1], forwnotbuy[trans]);
            }
            forwbuy=currbuy;
            forwnotbuy=currnotbuy;
        }
        return currbuy[k];
    }
};