class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>n-1||j>m-1)
        {
            return 0;
        }
        if(grid[i][j]==0)
        {
            return 0;
        }
        int ans = grid[i][j];
        grid[i][j] = 0;
        return ans+helper(grid,i+1,j)+helper(grid,i-1,j)+helper(grid,i,j-1)+helper(grid,i,j+1);
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<bool>temp(m,vector<int>(n,0));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                    maxi=max(maxi,helper(grid,i,j));
            }
        }
        return maxi;
    }
};