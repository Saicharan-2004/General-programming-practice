class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i=0; i<n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        vector<int>summer(n);
        for(int i = 0;i<n;i++)
        {
            summer[i]=players[i].second;
            for(int j = 0;j<i;j++)
            {
                if(players[j].second<=players[i].second)
                    summer[i]=max(summer[i],players[i].second+summer[j]);
            }
        }
        int ans = 0;
        for(auto it:summer)
        {
            ans = max(ans,it);
        }
        return ans;
    }
};