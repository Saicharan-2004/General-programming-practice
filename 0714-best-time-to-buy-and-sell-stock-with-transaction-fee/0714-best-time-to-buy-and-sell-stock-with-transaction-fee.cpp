class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        int currbuy=0,currnotbuy=0,forwbuy=0,forwnotbuy=0;
        // vector<int>curr(2,0),forw(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            currbuy=max(-prices[ind]+forwnotbuy,forwbuy);
            currnotbuy=max(prices[ind]-fee+forwbuy,forwnotbuy);
            forwbuy=currbuy;
            forwnotbuy=currnotbuy;
        }
        return currbuy;
    }
};