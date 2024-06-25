class Solution {
public: 
    void bfs(int i,int j,vector<vector<int>>&img,vector<vector<bool>>&visited,int color,int prevColor)
    {
        int n = img.size();
        int m = img[0].size();
        if(i<0 || j<0 || i>=n || j>=m)  return ;
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j] = true;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            img[x][y] = color;
            pair<int,int>uper = {x,y+1};
            pair<int,int>niche ={x,y-1};
            pair<int,int>aage ={x+1,y};
            pair<int,int>piche ={x-1,y};
            if(uper.second < m && visited[uper.first][uper.second] == 0 && img[uper.first][uper.second] == prevColor)
            {
                q.push(uper);
                visited[uper.first][uper.second] = true;
            }
            if(niche.second > -1 && visited[niche.first][niche.second] == 0 && img[niche.first][niche.second] == prevColor)
            {
                q.push(niche);
                visited[niche.first][niche.second] = true;
            }
            if(aage.first < n && visited[aage.first][aage.second] == 0 && img[aage.first][aage.second] == prevColor)
            {
                q.push(aage);
                visited[aage.first][aage.second] = true;
            }
            if(piche.first > -1 && visited[piche.first][piche.second] == 0 && img[piche.first][piche.second] == prevColor)
            {
                q.push(piche);
                visited[piche.first][piche.second] = true;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>visited(n+1,vector<bool>(m+1,0));
        bfs(sr,sc,image,visited,color,image[sr][sc]);
        return image;
    }
};