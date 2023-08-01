class Solution {
public:
    int helper(string str1,string str2,int ind1,int ind2,int n,int m,vector<vector<int>>&dp)
    {
        if(ind2==0)
        {
            return ind1;
        }
        else if(ind1==0)
        {
            return ind2;
        }
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(str1[ind1-1]==str2[ind2-1])
        {
            return dp[ind1][ind2]= helper(str1,str2,ind1-1,ind2-1,n,m,dp);
        }
        else
        {
            return dp[ind1][ind2]= 1+min(helper(str1,str2,ind1,ind2-1,n,m,dp),min(helper(str1,str2,ind1-1,ind2-1,n,m,dp),helper(str1,str2,ind1-1,ind2,n,m,dp)));
        }
    }
    int minDistance(string str1, string str2) 
    {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }   
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                if(str1[ind1-1]==str2[ind2-1])
                {
                    dp[ind1][ind2]= dp[ind1-1][ind2-1];
                }
                else
                {
                    dp[ind1][ind2]= 1+min(dp[ind1][ind2-1],min(dp[ind1-1][ind2-1],dp[ind1-1][ind2]));
                }
            }
        }
        return dp[n][m];
    }
};