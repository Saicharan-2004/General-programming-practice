class Solution {
public:
    // int helper(string s1,string s2,int ind1,int ind2,vector<vector<int>>&dp)
    // {
    //     if(ind1==0&&ind2==0)
    //     {
    //         return 0;
    //     }
    //     if(ind1==0)
    //     {
    //         int r=0;
    //         while(ind2>0)
    //         {
    //             r+=(int)s2[ind2-1];
    //             ind2--;
    //         }
    //         return r;
    //     }
    //     if(ind2==0)
    //     {
    //         int r=0;
    //         while(ind1>0)
    //         {
    //             r+=(int)s1[ind1-1];
    //             ind1--;
    //         }
    //         return r;
    //     }
    //     if(dp[ind1][ind2]!=-1)
    //     {
    //         return dp[ind1][ind2];
    //     }
    //     int ans=INT_MAX;
    //     if(s1[ind1-1]==s2[ind2-1])
    //     {
    //         ans= helper(s1,s2,ind1-1,ind2-1);
    //     }
    //     else
    //     {
    //         ans = min(ans, s1[ind1-1] + helper(s1,s2,ind1-1,ind2));
    //         ans = min(ans, s2[ind2-1] + helper(s1,s2,ind1,ind2-1));
    //     }
    //     return dp[ind1][ind2]= ans;
    // }
    int minimumDeleteSum(string s1, string s2) 
    {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=0;
        for(int ind2=1;ind2<=m;ind2++)
        {
            dp[0][ind2]=dp[0][ind2-1]+(int)s2[ind2-1];
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            dp[ind1][0]=dp[ind1-1][0]+(int)s1[ind1-1];
        }
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                int ans=INT_MAX;
                if(s1[ind1-1]==s2[ind2-1])
                {
                    ans = min(ans,dp[ind1-1][ind2-1]);
                }
                else
                {
                    ans = min(ans, s1[ind1-1] +dp[ind1-1][ind2]);
                    ans = min(ans, s2[ind2-1] +dp[ind1][ind2-1]);
                }
                dp[ind1][ind2]=ans;
            }
        }
        return dp[n][m];
    }
};