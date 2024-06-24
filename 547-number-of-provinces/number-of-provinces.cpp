class Solution {
public:
    void dfs(vector<vector<int>>mat,int val,vector<int>&visited)
    {
        visited[val] = 1;
        for(int i = 0;i<mat.size();i++)
        {
            if(val!=i && mat[val][i] && visited[i]!=1)
            {
                dfs(mat,i,visited);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i = 0 ;i<n;i++)
        {
            if(visited[i] == 0)
            {
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};