class Solution {
public:
    void dfs(vector<vector<int>>&mat,int val,vector<bool>&visited)
    {
        visited[val] = 1;
        for(int i = 0;i<mat.size();i++)
        {
            if(val!=i && mat[val][i] && visited[i]!=true)
            {
                dfs(mat,i,visited);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i = 0 ;i<n;i++)
        {
            if(visited[i] == false)
            {
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};