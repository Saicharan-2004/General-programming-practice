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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>tp;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                string it = accounts[i][j];
                if(tp.find(it) == tp.end())
                {
                    tp[it]=i;
                }
                else
                {
                   ds.unionByRank(i,tp[it]);
                }
            }
        }
        vector<vector<string>>ans(n);
        for(auto it:tp)
        {
            string now = it.first;
            int node = ds.findUltParent(it.second);
            ans[node].push_back(now);
        }
        vector<vector<string>>fin;
        for(int i = 0;i<n;i++)
        {
            if(ans[i].size() == 0)  continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(ans[i].begin(),ans[i].end());
            for(auto it:ans[i])
            {
                temp.push_back(it);
            }
            fin.push_back(temp);
        }
        return fin;
    }
};