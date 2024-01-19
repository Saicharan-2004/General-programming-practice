class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(j<0||j>matrix.size()-1)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=matrix[i][j]+min(helper(i-1,j,matrix,dp),min(helper(i-1,j+1,matrix,dp),helper(i-1,j-1,matrix,dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a=1e8,b=1e8,c=1e8;
                a=dp[i-1][j];
                if(j<n-1)
                {
                    b=dp[i-1][j+1];
                }
                if(j>=1)
                {
                    c=dp[i-1][j-1];
                }
                dp[i][j]=matrix[i][j]+min(a,min(b,c));
            }
        }//this step fills up the entire dp table and gives us all the possible smallest path sums uptill the last final row.
        //Now the minimum from the final row would give us the minimium falling path sum required in the question.
        int maxi=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxi=min(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};