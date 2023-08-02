class Solution {
public:
    int helper(vector<int>nums1,vector<int>nums2,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0||j<0)
        {
            return 0;
        }
        int ans=INT_MIN;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(nums1[i]==nums2[j])
        {
            ans=max(ans,1+helper(nums1,nums2,i-1,j-1,dp));
        }
        else
        {
            ans=max(ans,max(helper(nums1,nums2,i,j-1,dp),helper(nums1,nums2,i-1,j,dp)));
        }
        return dp[i][j]= ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int ans=INT_MIN;
                if(nums1[i-1]==nums2[j-1])
                {
                    ans=max(ans,1+dp[i-1][j-1]);
                }
                else
                {
                    ans=max(ans,max(dp[i-1][j],dp[i][j-1]));
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][m];
    }
};