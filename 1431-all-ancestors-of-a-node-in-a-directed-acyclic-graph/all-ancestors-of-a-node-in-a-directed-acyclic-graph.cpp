class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node,set<int>&curr,vector<bool>&visited)
    {
        visited[node] = true;
        for(auto it:adj[node])
        {
            if(visited[it]!=true)
            {
                dfs(adj,it,curr,visited);
                curr.insert(it);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n);
         vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<n;i++)
        {
            vector<bool>visited(n,false);
            set<int>curr;
            dfs(adj,i,curr,visited);
            vector<int>d(curr.begin(),curr.end());
            ans[i] = d;
        }
        return ans;
    }
};