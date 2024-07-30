class Solution {
public:
    void dfs(vector<vector<int>>&isConnected,vector<int>&visited,int node)
    {
        visited[node] = true;
        int n = isConnected.size();
        for(int i = 0;i<n;i++)
        {
            if(node != i && visited[i] == false && isConnected[node][i] == 1)
            {
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<vector<int>>adj(n+1);
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<n;j++)
        //     {
        //         if(isConnected[i][j] == true)
        //             adj[i].push_back(j);
        //     }
        // }
        int count =  0;
        vector<int>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i] == false)
            {
                dfs(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};