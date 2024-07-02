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
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>q;//This stores time taken to reach a particuar node + the nodeval
        vector<long long>dist(n,1e15);
        vector<long long>ways(n,0); 
        dist[0] = 0;//distance to reach a start node from start is 0.
        ways[0] = 1;//number of ways to reach start is 1.
        q.push({0,0});//Queue will be storing the time and the nodeval
        int modu = 1e9+7;
        while(!q.empty())
        {
            long long int node = q.top().second;
            long long int timeTillNow = q.top().first;
            q.pop();
            for(auto it:adj[node])
            {
                long long int val = it.first;
                long long int time  = it.second;
                if(timeTillNow + time < dist[val])
                {
                    dist[val] = timeTillNow + time;
                    ways[val] = ways[node] % modu;
                    q.push({timeTillNow + time,val});
                }
                else if(timeTillNow + time == dist[val])
                {
                    ways[val] = (ways[val]+ways[node]) % modu;
                }
            }
        }
        return ways[n-1]%modu;
    }
};