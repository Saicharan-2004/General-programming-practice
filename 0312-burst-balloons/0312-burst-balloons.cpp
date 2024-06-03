class Solution {
public:
    
    int helper(int start,int end,vector<int>nums,vector<vector<int>>&dp)
    {
        if(start>end)
        {
            return 0;
        }
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int maxi=-1;
        for(int i = start;i<=end;i++)
        {
            maxi = max(maxi,nums[start - 1]*nums[i]*nums[end + 1] + helper(start,i-1,nums,dp) + helper(i+1,end,nums,dp));
        }
        return dp[start][end] = maxi;
    }
    int maxCoins(vector<int>& nums) 
    {
        int end = nums.size();
        int start = 1;
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = n;i>=1 ;i--)
        {
            for(int j = 1;j<n-1;j++)
            {
                if(i>j)
                {
                    continue;
                }
                int maxi = -1;
                for(int k = i ;k<=j;k++)
                {
                    maxi = max(maxi,nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k-1] + dp[k+1][j]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[start][end];
    }
};