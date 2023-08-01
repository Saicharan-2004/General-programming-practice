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
        int mod=1e9+7;
        int n=s.length();
        int m=t.length();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                if(s[ind1-1]==t[ind2-1])
                {
                    dp[ind1][ind2]= dp[ind1-1][ind2-1]%mod+dp[ind1-1][ind2]%mod;
                }
                else
                {
                    dp[ind1][ind2]= dp[ind1-1][ind2]%mod;
                }
            }
        }
        return dp[n][m];
    }
};