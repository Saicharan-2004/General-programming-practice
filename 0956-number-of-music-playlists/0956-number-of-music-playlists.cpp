class Solution {
public:
    const int mod=1e9+7;
    long long helper(int goal,int n,int k,vector<vector<int>>&dp)
    {
        if(n==0&&goal==0)
            return 1;
        if(n==0||goal==0)
            return 0;
        if(dp[n][goal]!=-1)
        {
            return dp[n][goal];
        }
        long long int pick=((helper(goal-1,n-1,k,dp)%mod)*n)%mod;
        long long int notpick=((helper(goal-1,n,k,dp)%mod)*(max(n-k,0)))%mod;
        return dp[n][goal]=(pick+notpick)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return helper(goal,n,k,dp);
    }
};