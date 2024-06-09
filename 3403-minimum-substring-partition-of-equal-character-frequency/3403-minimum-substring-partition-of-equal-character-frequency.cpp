class Solution {
public:
    int helper(int ind, string s,vector<int>dp) {
        if (ind < 0)
            return 0;
        int ans = s.size();
        unordered_map<char,int>tp;
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        for (int i = ind; i >= 0; i--) 
        {
            tp[s[i]]++;
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for (auto it : tp) {
                maxi = max(maxi, it.second);
                mini = min(mini, it.second);
            }
            // cout<<maxi<<" "<<mini<<" : ";
            if (maxi == mini) 
            {
                ans = min(ans, 1 + helper(i - 1, s ,dp));
            } 
            else 
            {
                continue;
            }
        }
        return dp[ind] = ans;
    }
    int minimumSubstringsInPartition(string s) {
        vector<int>dp(s.size()+1,0);
        // return helper(s.size()-1, s,dp);
        for(int ind = 0;ind<s.size();ind++)
        {
            int ans = s.size();
            unordered_map<char,int>tp;
            for (int i = ind; i >= 0; i--) 
            {
                tp[s[i]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for (auto it : tp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                // cout<<maxi<<" "<<mini<<" : ";
                if (maxi == mini) 
                {
                    if(i > 0)
                    {
                        ans = min(ans,1+dp[i-1]);
                    }
                    else
                    {
                        ans = min(ans,1);
                    }
                } 
                else 
                {
                    continue;
                }
            }
            dp[ind] = ans;
        }
        return dp[s.size() - 1];
    }
};