class Solution {
public:
    int helper(vector<int>&days,vector<int>&costs,int ind,vector<int>&dp)
    {
        if(ind>=days.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int one=costs[0]+helper(days,costs,ind+1,dp);
        int seven=costs[1]+helper(days,costs,upper_bound(days.begin(),days.end(),days[ind]+6)-days.begin(),dp);
        int thirty=costs[2]+helper(days,costs,upper_bound(days.begin(),days.end(),days[ind]+29)-days.begin(),dp);
        return dp[ind]= min(one,min(seven,thirty));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return helper(days,costs,0,dp);
    }
};