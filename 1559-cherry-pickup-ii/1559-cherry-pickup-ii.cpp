class Solution {
public:
    // int helper(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
    // {
    //     if(j1<0||j1>=m||j2<0||j2>=m)
    //     {
    //         return -1e8;
    //     }
    //     if(i==n-1)
    //     {
    //         if(j1==j2)
    //         {
    //             return grid[i][j1];
    //         }
    //         return grid[i][j1]+grid[i][j2];
    //     }
    //     if(dp[i][j1][j2]!=-1)
    //         return dp[i][j1][j2];
    //     int maxi=INT_MIN;
    //     for(int g1=-1;g1<=1;g1++)
    //     {
    //         for(int g2=-1;g2<=1;g2++)
    //         {
    //             int value=0;
    //             if(j1==j2)
    //             {
    //                 value=grid[i][j1];
    //             }
    //             else
    //             {
    //                 value=grid[i][j1]+grid[i][j2];
    //             }
    //             maxi=max(maxi,value+helper(i+1,j1+g1,j2+g2,n,m,grid,dp));
    //         }
    //     }
    //     return dp[i][j1][j2]=maxi;
    // }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[n-1][j1][j2]= grid[n-1][j1];
                }
                else
                {
                    dp[n-1][j1][j2]= grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=INT_MIN;
                    for(int g1=-1;g1<=1;g1++)
                    {
                        for(int g2=-1;g2<=1;g2++)
                        {
                            int value=0;
                            if(j1==j2)
                            {
                                value=grid[i][j1];
                            }
                            else
                            {
                                value=grid[i][j1]+grid[i][j2];
                            }
                            if(j1+g1>=0&&j1+g1<m&&j2+g2>=0&&j2+g2<m)
                                value+=dp[i+1][j1+g1][j2+g2];
                            else
                                value+=-1e8;
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};