class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(isConnected[i][j] == true)
                    adj[i].push_back(j);
            }
        }
        int count =  0;
        vector<int>visited(n,false);
        for(int i=0;i<n;i++)
        {
            int curr = i;
            if(visited[i] == false)
            {
                queue<int>q;
                q.push(curr);
                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    visited[front] = true;
                    for(auto it:adj[front])
                    {
                        if(visited[it] == false)
                        {
                            q.push(it);
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};