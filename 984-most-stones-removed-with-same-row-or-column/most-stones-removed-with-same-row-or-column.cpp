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
    int removeStones(vector<vector<int>>& stones) {
        int max_x = -1;
        int max_y = -1;
        for(auto it:stones)
        {
            max_x = max(max_x,it[0]);
            max_y = max(max_y,it[1]);
        }
        DisjointSet ds(max_x + max_y + 1);
        for(auto it:stones)
        {
            int row = it[0];
            int col = 1 + max_x + it[1];
            ds.unionBySize(row,col);
        }
        int ans = 0;
        for(int i = 0;i<ds.parent.size();i++)
        {
            if(i == ds.parent[i] && ds.size[i] != 1)
            {
                ans++;
            }
        }
        return stones.size()-ans;
    }
};