class Solution {
public:
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
        for(int i = 0;i<n;i++)
        {
            dist[i][i] = 0;
        }
        for(int via = 0;via < n;via++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
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