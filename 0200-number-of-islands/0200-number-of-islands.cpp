class Solution {
public:
    void dfs(vector<vector<bool>>&visited,int i,int j,vector<vector<char>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j >=m) return ;
        if(visited[i][j] == true || grid[i][j] == '0')   return ;
        visited[i][j] = true;
        dfs(visited,i-1,j,grid);
        dfs(visited,i+1,j,grid);
        dfs(visited,i,j-1,grid);
        dfs(visited,i,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(visited[i][j]==false && grid[i][j] == '1')
                {
                    ans++;
                    dfs(visited,i,j,grid);
                }
            }
        }
        return ans;
    }
};