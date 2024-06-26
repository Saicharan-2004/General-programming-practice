class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n == 1 || m == 1)    return ;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i+=n-1)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == false)
                {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        for(int i = 0;i<m;i+=m-1)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[j][i] == 'O' && visited[j][i] == false)
                {
                    q.push({j,i});
                    visited[j][i] = true;
                }
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
                if(!visited[i][j] && board[i][j] == 'O')    
                    board[i][j] = 'X';
            }
        }
    }
};