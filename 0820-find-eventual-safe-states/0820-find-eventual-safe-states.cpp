class Solution {
public:
    vector<int>fin;
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
        fin.push_back(start);
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>safe;
        isCyclic(n,graph);
        sort(fin.begin(),fin.end());//can avoid this;
        return fin;
    }
};