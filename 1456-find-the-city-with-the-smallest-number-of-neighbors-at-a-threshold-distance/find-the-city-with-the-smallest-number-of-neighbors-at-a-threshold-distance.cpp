class Solution {
public:
    
    vector<int>dijkstra(int sc,vector<vector<int>>&edges,int n)
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges)
        {
            int x = it[0];
            int y = it[1];
            int wt = it[2];
            adj[x].push_back({y,wt});
            adj[y].push_back({x,wt});
        }
        vector<int>dist(n,1e9);
        dist[sc] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,sc});
        while(!pq.empty())
        {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int currNode = it.first;
                int edgeWt = it.second;
                if(edgeWt + currDist < dist[currNode])
                {
                    dist[currNode] = edgeWt + currDist;
                    pq.push({edgeWt+currDist,currNode});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto it:edges)
        {
            int x = it[0];
            int y = it[1];
            int wt = it[2];
            dist[x][y] = wt;
            dist[y][x] = wt;
        }

        //Dijkstra at every node(To improve TC)

        for(int i = 0;i<n;i++)
        {
            dist[i] = dijkstra(i,edges,n);
        }


        //Floyd Warshall Algorithm(standard)

        // for(int i = 0;i<n;i++)
        // {
        //     dist[i][i] = 0;
        // }
        // for(int via = 0;via < n;via++)
        // {
        //     for(int i = 0;i<n;i++)
        //     {
        //         for(int j = 0;j<n;j++)
        //         {
        //             dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
        //         }
        //     }
        // }
        int ans = -1;
        int maxCounter = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            int counter = 0;
            for(int j = 0;j<n;j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    counter++;
                }
            }
            if(counter <= maxCounter)
            {
                maxCounter = counter;
                ans = i;
            }
        }
        return ans;
    }
};