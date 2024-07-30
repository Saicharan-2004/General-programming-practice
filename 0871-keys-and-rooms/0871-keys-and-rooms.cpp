class Solution {
public:
    void dfs(int node,vector<int>&visited,vector<vector<int>>& adj)
    {
        visited[node] = 1;
        for(auto it:adj[node])
        {
            if(visited[it] == 0)
            {
                dfs(it,visited,adj);
            }
        }
        // ans.push_back(node);
        // visited[node] = 1;
        // st.push(node);
        return ;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        visited[0] = true;
        dfs(0,visited,rooms);
        for(auto it:visited)
        {
            if(it == false)
            {
                return false;
            }
        }
        return true;
    }
};