class DisjointSet
{
    public:
    vector<int>size,rank,parent;
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
    void unionByParent(int u,int v)
    {
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        parent[ult_u] = ult_v;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int TotalComponents = 0;
        int extraEdges = 0;
        DisjointSet ds(n);
        for(auto it:connections)
        {
            if(ds.findUltParent(it[0]) == ds.findUltParent(it[1]))
            {
                extraEdges++;
            }
            else
            {
                ds.unionByRank(it[0],it[1]);
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(i == ds.parent[i])
            {
                TotalComponents++;
            }
        }
        if(extraEdges >= TotalComponents - 1)
        {
            return TotalComponents - 1;
        }
        return -1;
    }
};