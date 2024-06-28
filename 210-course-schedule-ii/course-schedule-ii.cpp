class Solution {
public: 
    vector<int>ans;
    bool dfs(int start,vector<vector<int>> &adj,vector<int>&visited)
    {
        visited[start] = 2;
        for(auto it:adj[start])
        {
            if(visited[it] == 0)
            {
                if(dfs(it,adj,visited))  
                    return true;
            }
            else if(visited[it] == 2)
            {
                return true;
            }
        }
        ans.push_back(start);
        visited[start] = 1;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &adj)
    {
        vector<int>visited(V,0);
        for(int i = 0;i<V;i++)
        {
            if(visited[i] == 0)
            {
                bool ans = dfs(i,adj,visited);
            }
        }
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        isCyclic(numCourses,adj);
        if(ans.size() != numCourses)    return {};
        return ans;
    }
};