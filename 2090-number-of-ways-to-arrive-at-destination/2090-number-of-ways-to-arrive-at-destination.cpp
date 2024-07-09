class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            int x = it[0];
            int y = it[1];
            int wt = it[2];
            pair<int,int> tx = {y,wt};
            pair<int,int> ty = {x,wt};
            adj[x].push_back(tx);
            adj[y].push_back(ty);
        }
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;//This stores time taken to reach a particuar node + the nodeval
        vector<long long>dist(n,1e15);
        vector<long long>ways(n,0); 
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int modu = 1e9+7;
        
        while(!pq.empty())
        {
            long long int dis = pq.top().first;
            long long int curr = pq.top().second;
            pq.pop();
            for(auto it:adj[curr])
            {
                long long int next = it.first;
                long long int wt = it.second;
                if(wt + dis < dist[next])
                {
                    dist[next] = wt + dis;
                    pq.push({wt+dis,next});
                    ways[next] = ways[curr] % modu;
                }
                else if(wt + dis == dist[next])
                {
                    ways[next] = (ways[next] + ways[curr])%modu;
                }
            }
        }
        return ways[n-1]%modu;
    }
};