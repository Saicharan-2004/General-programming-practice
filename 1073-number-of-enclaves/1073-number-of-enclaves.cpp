class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>& visited,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m)
        {
            return ;
        }
        visited[i][j] = true;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int ii = 0;ii<4;ii++)
        {
            int row = i + dx[ii];
            int col = j + dy[ii];
            if(row>-1 && col >-1 && row < n && col < m && visited[row][col] == false && grid[row][col] == 1)
            {
                dfs(row,col,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        if(n == 1 || m == 1)    return 0;
        for(int i = 0;i<n;i+=n-1)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,visited,grid);
                }
            }
        }
        for(int j = 0;j<m;j+=m-1)
        {
            for(int i= 0;i<n;i++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,visited,grid);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};