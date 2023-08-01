class Solution {
public:
    int helper(vector<int>cost,int ind,vector<int>&dp)
    {
        if(ind==cost.size()-1)
        {
            return dp[ind]=cost[ind];
        }
        if(ind==cost.size()-2)
        {
            return dp[ind]=cost[ind];
        }
        if(ind>=cost.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int d=helper(cost,ind+1,dp);
        int r=helper(cost,ind+2,dp);
        return dp[ind]=cost[ind]+min(d,r);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int>dp1(cost.size(),-1);
        for(int i=0;i<cost.size();i++)
        {
            if(i<=1)
            {
                dp1[i]=cost[i];
            }
            else
            {
                dp1[i]=cost[i]+min(dp1[i-1],dp1[i-2]);
            }
        }
        return min(dp1[cost.size()-1],dp1[cost.size()-2]);
    }
};