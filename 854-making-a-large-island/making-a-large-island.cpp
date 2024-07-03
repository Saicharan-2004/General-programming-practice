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
    bool isValid(int row,int col,int n,int m)
    {
        return row>=0 && col >=0 && row < n && col < m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        // int m = grid[0].size();
        if(n==1)
        {
            return 1;
        }
        DisjointSet ds(n*n);
        // vector<vector<int>>visited(n,vector<int>(m,0));
        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};
        int ans = -1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int ii = 0;ii<4;ii++)
                    {
                        int currNodeVal = i*n + j;
                        int row = i + dx[ii];
                        int col = j + dy[ii];
                        if(isValid(row,col,n,n))
                        {
                            if(grid[row][col] == 1)
                            {
                                int adjNodeVal = row*n + col;
                                ds.unionBySize(adjNodeVal,currNodeVal);
                                ans = max(ans,ds.size[ds.findUltParent(adjNodeVal)]);
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                // vector<int>vis(n*n,0);
                if(grid[i][j] == 0)
                {
                    unordered_set<int>check;
                    int currTotalSize = 1;
                    for(int ii = 0;ii<4;ii++)
                    {
                        int row = i + dx[ii];
                        int col = j + dy[ii];
                        if(isValid(row,col,n,n))
                        {
                            if(grid[row][col] == 1)
                            {
                                int adjNodeVal = row*n + col;
                                int node = ds.findUltParent(adjNodeVal);
                                if(check.find(node) == check.end())
                                {
                                    currTotalSize += ds.size[node];
                                    check.insert(node);
                                }
                            }
                        }
                    }
                    ans = max(ans,currTotalSize);
                }
            }
        }
        return ans;
    }
};