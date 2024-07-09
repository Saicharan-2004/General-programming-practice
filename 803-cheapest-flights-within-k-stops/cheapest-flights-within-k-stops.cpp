class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src] = 0;
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        queue<pair<int,pair<int,int>>>pq;
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;// node,Cost to reach that node.
        pq.push({-1,{0,src}});
        //This means we are giving more priority to stops rather than distance.
        int maxi = INT_MAX;
        while(!pq.empty())
        {
            int cost = pq.front().second.first;
            int node = pq.front().second.second;
            int stops = pq.front().first;
            pq.pop();
            if(node == dst)
            {
                maxi = min(maxi,cost);
            }
            for(auto it:adj[node])
            {
                int oneTripCost = it.second;
                int currVal = it.first;
                if(stops+1 <=k && dist[currVal] > cost + oneTripCost)
                {
                    dist[currVal] = cost + oneTripCost;
                    pq.push({stops+1,{cost + oneTripCost, currVal}});
                }
            }
        }
        return maxi == INT_MAX ? -1 : maxi;
    }
};