class Solution {
public:
    bool dfs(int start,vector<vector<int>>adj,vector<int>&visited)
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
        visited[start] = 1;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>adj)
    {
        vector<int>visited(V,0);
        for(int i = 0;i<V;i++)
        {
            if(visited[i] == 0)
            {
                bool ans = dfs(i,adj,visited);
                if(ans) 
                    return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prereq)
        {
            adj[it[0]].push_back(it[1]);
        }
        return !isCyclic(numCourses,adj);
    }
};