class helper{
public:
    int x;
    int y;
    int time;
    helper(int x,int y,int time)
    {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<helper>q;
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(helper(i,j,0));
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty())
        {
            helper front = q.front();
            q.pop();
            maxi = max(maxi,front.time);
            for(int i = 0;i<4;i++)
            {
                int row = front.x + dx[i];
                int col = front.y + dy[i];
                if(row>=0 && col>=0 && row<n && col <m && grid[row][col] == 1)
                {
                    q.push(helper(row,col,front.time+1));
                    grid[row][col] = 2;
                }
            }
        }
        for(auto it:grid)
        {
            for(auto i:it)
            {
                if(i == 1)
                {
                    return -1;
                }
            }
        }
        return maxi;
    }
};