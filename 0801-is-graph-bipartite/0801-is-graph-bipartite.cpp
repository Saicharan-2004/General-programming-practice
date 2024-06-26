class Solution {
public:
    bool bfs(int start,vector<vector<int>>&graph,vector<int>&visited)
    {
        queue<int>q;
        int n = graph.size();
        bool color = true;
        q.push(start);
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(auto it:graph[front])
            {
                if(visited[it] == -1)
                {
                    visited[it] = !visited[front];
                    q.push(it);
                }
                else
                {
                    if(visited[it] == visited[front])
                    {
                        return false;
                    }
                }
            }
        }
        return true;

    }
    bool dfs(int start,vector<vector<int>>&graph,vector<int>&visited,int color)
    {
        visited[start] = color;
        for(auto it:graph[start])
        {
            if(visited[it] == -1)
            {
                if(!dfs(it,graph,visited,1-color))
                {
                    return false;
                }
            }
            else
            {
                if(visited[it] == color)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);
        //-1 indicating that the node is not colored.
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == -1)
            {
                bool r = bfs(i,graph,visited);
                // bool r = dfs(i,graph,visited,0);
                if(!r)  return false;
            }
        }
        return true;
    }
};