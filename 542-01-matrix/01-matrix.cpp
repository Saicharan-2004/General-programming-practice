class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    mat[i][j] = 2;
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int score = q.front().second;
            ans[x][y] = score;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int row = x + dx[i];
                int col = y + dy[i];
                if(row>=0 && col >=0 && row <n && col <m && mat[row][col] != 2)
                {
                    mat[row][col] = 2;
                    q.push({{row,col},score+1});
                }
            }
        }
        return ans;
    }
};