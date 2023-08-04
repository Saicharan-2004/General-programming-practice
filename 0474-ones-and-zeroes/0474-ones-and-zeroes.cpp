class Solution {
public:
    int helper(vector<string>arr,int m,int n,int ind,vector<vector<vector<int>>>&dp)
    {
        if(m==0&&n==0)
        {
            return 0;
        }
        if(ind<0)
        {
            return 0;
        }
        if(dp[ind][m][n]!=-1)
        {
            return dp[ind][m][n];
        }
        int nottake=helper(arr,m,n,ind-1,dp);
        int countOnes=0;
        int countZeros=0;
        string rt=arr[ind];
        for(int i=0;i<rt.length();i++)
        {
            if(rt[i]=='1')
                countOnes++;
            else
                countZeros++;
        }
        int take=0;
        if(m>=countZeros&&n>=countOnes)
        {
            take=1+helper(arr,m-countZeros,n-countOnes,ind-1,dp);
        }
        return dp[ind][m][n]= max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int si=strs.size();
        // vector<vector<vector<int>>>dp(si+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        vector<vector<int>>curr(m+1,vector<int>(n+1,0));
        vector<vector<int>>forw(m+1,vector<int>(n+1,0));
        for(int ind=si-1;ind>=0;ind--)
        {
            int countOnes=count(strs[ind].begin(),strs[ind].end(),'1');
            int countZeros=strs[ind].length()-countOnes;
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    int nottake=forw[j][k];
                    int take=0;
                    if(j>=countZeros&&k>=countOnes)
                    {
                        take=1+forw[j-countZeros][k-countOnes];
                    }
                    curr[j][k]=max(take,nottake);
                }
            }
            forw=curr;
        }
        return curr[m][n];
    }
};