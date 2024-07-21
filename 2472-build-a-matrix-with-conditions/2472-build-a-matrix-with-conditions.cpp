class Solution {
public:
    vector<int>topo(vector<int>inDegree,vector<vector<int>>edges,int k)
    {
        vector<vector<int>>adj(k+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        queue<int>q;
        for(int i = 1;i<=k;i++)
        {
            if(inDegree[i] == 0) q.push(i);
        }
        // vector<int>visited(K+1,0);
        vector<int>ans;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            if(inDegree[front] == 0)
            {
                ans.push_back(front);
            }
            for(auto it:adj[front])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>inDegreeForRow(k+1,0);
        for(auto it:rowConditions)
        {
            inDegreeForRow[it[1]]++;
        }
        // for(auto it:inDegreeForRow)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        vector<int>inDegreeForCol(k+1,0);
        for(auto it:colConditions)
        {
            inDegreeForCol[it[1]]++;
        }
        vector<int>toporow = topo(inDegreeForRow,rowConditions,k);
        vector<int>topocol = topo(inDegreeForCol,colConditions,k);
        if(toporow.size()!=k || topocol.size()!=k)  return {};
        // for(auto it:toporow)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:topocol)
        // {
        //     cout<<it<<" ";
        // }
        vector<vector<int>> arr(k, vector<int>(k));
        vector<int> pos_i(k+1, -1), pos_j(k+1, -1);
        for(int i=0; i<k; i++){
            pos_i[toporow[i]]=i;
            pos_j[topocol[i]]=i;
        }
        for(int x=1; x<=k; x++)
            arr[pos_i[x]][pos_j[x]]=x;
        return arr;
        // int num = 1;
        // int i = 0;
        // int j = 0;
        // while(i<toporow.size() && j<topocol.size())
        // {
        //     ans[toporow[i]-1][topocol[j]-1] = num;
        //     num++;
        //     i++;
        //     j++;
        // }
        // while(i<toporow.size())
        // {
        //     ans[toporow[i]-1][toporow[i]-1] = num;
        //     cout<<num<<endl;
        //     num++;
        //     i++;
        // }
        // while(j<topocol.size())
        // {
        //     ans[topocol[j]-1][topocol[j]-1] = num;
        //     // cout<<num<<endl;
        //     num++;
        //     j++;
        // }
        // return ans;
    }
};