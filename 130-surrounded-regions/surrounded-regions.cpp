class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int j = 0;j<m;j++)
        {
            if(board[0][j] == 'O' && visited[0][j] == false)
            {
                q.push({0,j});
                visited[0][j] = true;
            }
            if(board[n-1][j] == 'O' && visited[n-1][j] == false)
            {
                q.push({n-1,j});
                visited[n-1][j] = true;
            }
        }
        for(int j = 0;j<n;j++)
        {
            if(board[j][0] == 'O' && visited[j][0] == false)
            {
                q.push({j,0});
                visited[j][0] = true;
            }
            if(board[j][m-1] == 'O' && visited[j][m-1] == false)
            {
                q.push({j,m-1});
                visited[j][m-1] = true;
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int row = x + dx[i];
                int col = y + dy[i];
                if(row>=0 && col >=0 && row <n && col <m && board[row][col] == 'O' && visited[row][col]!=true)
                {
                    visited[row][col]=true;
                    q.push({row,col});
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(visited[i][j] == false && board[i][j] == 'O')    
                    board[i][j] = 'X';
            }
        }
    }
};