class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        if(grid[0][0] == 0)
            dist[0][0] = 0;
        else
            return -1;
        pq.push({{0,0},0});
        while(!pq.empty())
        {
            auto it = pq.front();
            int dis = it.first.first;
            int x = it.first.second;
            int y = it.second;
            pq.pop();
            for(int i = -1;i<=1;i++)
            {
                for(int j = -1;j<=1;j++)
                {
                    if(i==0 && j==0)
                    {
                        continue;
                    }
                    else
                    {
                        int row = x + i;
                        int col = y + j;
                        if(row < n && row >-1 && col < m && col > -1 && dist[row][col] > dis + 1)
                        {
                           if(grid[row][col] == 0)
                           {
                                dist[row][col] = dis + 1;
                                pq.push({{dis+1,row},col});
                           }
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1] == 1e9 ? -1 :1 + dist[n-1][m-1];
    }
};