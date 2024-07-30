class Solution {
public:
    vector<int>ans;
    bool dfs(int node,vector<int>&visited,vector<vector<int>>& adj)
    {
        visited[node] = 2;
        for(auto it:adj[node])
        {
            if(visited[it] == 0)
            {
                if(dfs(it,visited,adj))
                {
                    return true;
                }
            }
            else if(visited[it] == 2)
            {
                return true;
            }
        }
        ans.push_back(node);
        visited[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) 
    {
        int n = adj.size();
        vector<int>visited(n,false);
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                dfs(i,visited,adj);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};