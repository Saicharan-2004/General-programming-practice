class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        unordered_set<int>tp;
        int n = grid.size();
        int m = grid[0].size();
        for(int j = 0;j<m;j++)
        {
            int checker = grid[0][j];
            for(int i = 0;i<n;i++)
            {
                if(grid[i][j] != checker)
                    return false;
            }
        }
        for(int i = 1;i<m;i++)
        {
           if(grid[0][i] == grid[0][i-1])   return false;
        }
        return true;
    }
};