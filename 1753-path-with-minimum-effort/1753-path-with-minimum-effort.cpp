class Solution {
public:
    int helper(vector<vector<int>>& grid) {
        set<pair<pair<int,int>,int>>pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.insert({{0,0},0});
        int dx [] = {1,0,-1,0};
        int dy [] = {0,1,0,-1};
        while(!pq.empty())
        {
            auto it = *(pq.begin());
            int dis = it.first.first;//ab tak ka max dist.
            int x = it.first.second;
            int y = it.second;
            pq.erase(it);
            for(int i = 0;i<4;i++)
            {
                int row = x + dx[i];
                int col = y + dy[i];
                if(row < n && row >-1 && col < m && col > -1)
                {
                    int currDiff = abs(grid[row][col] - grid[x][y]);
                    int maxDiff = max(currDiff,dis);
                    if(dist[row][col] > maxDiff)
                    {
                        dist[row][col] = min(maxDiff,dist[row][col]);
                        pq.insert({{maxDiff,row},col});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return helper(heights);
    }
};