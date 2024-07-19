class Solution {
public:
    void contriCalc(vector<vector<int>>adj,vector<int>&contri,int start,int end,int n)
    {
        vector<int>visited(n,false);
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int>dist(n,INT_MAX);
        vector<int>par(n,0);
        for(int i = 0;i<n;i++)
        {
            par[i] = i;
        }
        dist[start] = 0;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int node = front.first;
            int currMin = front.second;
            if(node == end)
            {
                contri[node]++;
                while(par[node] != node)
                {
                    node = par[node];
                    contri[node]++;
                }
                return ;
            }
            for(auto it:adj[node])
            {
                if(dist[it] > currMin + 1)
                {
                    dist[it] = currMin + 1;
                    par[it] = node;
                    q.push({it,currMin+1});
                }
            }
        }
    }
    pair<int,int> dfs(vector<vector<int>>adj,vector<int>price,int n,int node,vector<int>contri,int parent)
    {
        int currHalved = (price[node]/2) * contri[node];
        int currNotHalved = price[node] * contri[node];
        for(auto it:adj[node])
        {
            if(it == parent)    continue;
            auto ans = dfs(adj,price,n,it,contri,node);
            currNotHalved += min(ans.first,ans.second);
            currHalved += ans.second;
        }
        return {currHalved,currNotHalved};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>contri(n,0);
        for(auto it:trips)
        {
            contriCalc(adj,contri,it[0],it[1],n);
        }
        auto ans = dfs(adj,price,n,0,contri,-1);
        return min(ans.first,ans.second);
    }
};