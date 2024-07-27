class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>>adj,int start)
    {
        vector<int>dist(26,INT_MAX);
        dist[start] = 0;
        queue<pair<int,int>>q;
        q.push({start,0});
        while(!q.empty())
        {
            auto front = q.front();//first->node,second->distance
            q.pop();
            for(auto it:adj[front.first])
            {
                if(front.second + it.second < dist[it.first])
                {
                    dist[it.first] = front.second + it.second;
                    q.push({it.first,dist[it.first]});
                }
            }
        }
        for(int i = 0;i<dist.size();i++)
        {
            if(dist[i] == INT_MAX)  dist[i] = -1;
        }
        return dist;
    }
    long long helper(vector<char>&original,vector<char>&changed,vector<int>&cost,string source,string target)
    {
        vector<vector<pair<int,int>>>adj(26);
        for(int i = 0;i<original.size();i++)
        {
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<int>>dist(26,vector<int>(26,-1));
        for(int i = 0;i<26;i++)
        {
            dist[i] = dijkstra(adj,i);
        }
        long long ans = 0;
        for(int i = 0;i<source.size();i++)
        {
            int curr = dist[source[i] - 'a'][target[i] - 'a'];
            if(curr == -1)
            {
                return -1;
            }
            ans+=curr;
        }
        return ans;
    }
    long long helper2(vector<char>&original,vector<char>&changed,vector<int>&cost,string source,string target)
    {
        vector<vector<pair<int,int>>>adj(26);
        for(int i = 0;i<original.size();i++)
        {
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<long long int>>dist(26,vector<long long int>(26,INT_MAX));
        for(int i = 0;i<original.size();i++)
        {
            dist[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i],dist[original[i] - 'a'][changed[i] - 'a']);
        }
        for(int k = 0;k<26;k++)
        {
            for(int i = 0;i<26;i++)
            {
                for(int j = 0;j<26;j++)
                {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0;i<source.size();i++)
        {
            if(source[i] == target[i])
            {
                continue;
            }
            int curr = dist[source[i] - 'a'][target[i] - 'a'];
            if(curr >= INT_MAX)
            {
                return -1;
            }
            ans+=curr;
        }
        return ans;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        return helper2(original,changed,cost,source,target);
    }
};