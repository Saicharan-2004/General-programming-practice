class Solution {
public:
    int mod=1e9+7;
    long long int helper(int n,int k,vector<vector<int>>&dp)
    {
        if(k==0)
        {
            return 1;
        }
        if(k<0||n<=0)
        {
            return 0;
        }
        if((k)>(n*(n-1))/2)
        {
            return 0;
        }
        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        return dp[n][k]=(helper(n-1, k,dp)+helper(n, k-1,dp)-helper(n-1, k-n,dp)+mod)%mod;
    }
    int kInversePairs(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return (int)helper(n,k,dp);
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i][0]=1;
        // }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=k;j++)
        //     {
        //         if((j)>(i*(i-1))/2)
        //         {
        //             dp[i][j]=0;
        //             break;
        //         }
        //         dp[i][j]=(dp[i-1][j]%modu+dp[i][j-1]%modu)%modu;
        //         if(j>=n)
        //         {
        //             dp[i][j]=(dp[i][j] - dp[i-1][j-i])%modu;
        //         }
        //     }
        // }
        // return (int)dp[n][k]%modu;
    }
};