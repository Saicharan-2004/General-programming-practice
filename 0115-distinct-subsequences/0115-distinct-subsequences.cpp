class Solution {
public:
    int helper(string s1,string s2,int ind1,int ind2,vector<vector<int>>&dp)
    {
        if(ind2<0)
        {
            return 1;
        }
        if(ind1<0)
        {
            return 0;
        }
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(s1[ind1]==s2[ind2])
        {
            return dp[ind1][ind2]= helper(s1,s2,ind1-1,ind2-1,dp)+helper(s1,s2,ind1-1,ind2,dp);
        }
        else
        {
            return dp[ind1][ind2]= helper(s1,s2,ind1-1,ind2,dp);
        }
    }
    int numDistinct(string s, string t) 
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,t,n-1,m-1,dp);
    }
};