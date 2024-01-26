class Solution {
public:
    int modu=1e9+7;
    int helper(int m,int n,int ind,int maxMove,int i,int j,vector<vector<vector<int>>>&dp)
    {
        if(i>=m||i<0)
        {
            return 1;
        }
        if(j>=n||j<0)
        {
            return 1;
        }
        if(ind>=maxMove)
        {
            return 0;
        }
        if(dp[i][j][ind]!=-1)
        {
            return dp[i][j][ind];
        }
        int left=helper(m,n,ind+1,maxMove,i,j-1,dp);
        int right=helper(m,n,ind+1,maxMove,i,j+1,dp);
        int up=helper(m,n,ind+1,maxMove,i-1,j,dp);
        int down=helper(m,n,ind+1,maxMove,i+1,j,dp);
        return  dp[i][j][ind]=((left+right)%modu+(up+down)%modu)%modu;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return helper(m,n,0,maxMove,startRow,startColumn,dp);
    }
};