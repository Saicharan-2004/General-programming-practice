class DisjointSet
{
    vector<int>size,rank,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1);//total size of the connected component below itself.
        rank.resize(n+1);//uss particular node ke niche kya kya hai.
        parent.resize(n+1);//ultparents of individual nodes.
        for(int i = 0;i<=n;i++)
        {
            size[i] = 1;
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int findUltParent(int u)
    {
        if(u == parent[u])  return u;
        return parent[u] = findUltParent(parent[u]);
    }
    void unionByRank(int u,int v)
    {
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        if(ult_u == ult_v)  return ;
        if(rank[ult_v] == rank[ult_u])
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
        else
        {
            if(rank[ult_v] > rank[ult_u])
            {
                parent[ult_u] = ult_v;
            }
            else
            {
                parent[ult_v] = ult_u;
            }
        }
    }
    void unionBySize(int u ,int v)
    {
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        if(ult_u == ult_v)  return ;
        if(size[ult_v] <= size[ult_u])
        {
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
        else
        {
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
    void unionTemp(int u,int v)
    {
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        parent[ult_u] = ult_v;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> adj;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({weight, {i, j}});
            }
        }
        sort(adj.begin(),adj.end());
        DisjointSet ds(adj.size());
        int fin = 0;
        for(auto it:adj)
        {
            int x = it.second.first;
            int y = it.second.second;
            int wt = it.first;
            if(ds.findUltParent(x) == ds.findUltParent(y))
            {
                continue;
            }
            else
            {
                ds.unionTemp(x,y);
                fin+=wt;
            }
        }
        return fin;
    }
};