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
                dfs(i,adj,visited);
            }
        }
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i = 0;i<numCourses;i++)
        {
            if(indegree[i] == 0)    
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                    ans.push_back(it);   
                }
            }
        }
        // isCyclic(numCourses,adj);
        if(ans.size() != numCourses)    return {};
        // reverse(ans.begin(),ans.end());
        return ans;

    }
};