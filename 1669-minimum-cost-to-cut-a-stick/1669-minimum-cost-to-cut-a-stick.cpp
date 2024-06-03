class Solution {
public:
    // int helper(int start,int end,vector<int>cuts,int n,vector<vector<int>>&dp)
    // {
    //     if(start>end)
    //     {
    //         return 0;
    //     }
    //     int mini = INT_MAX;
    //     if(dp[start][end]!=-1)
    //     {
    //         return dp[start][end];
    //     }
    //     for(int i = start;i<=end;i++)
    //     {
    //         mini = min(mini,cuts[end+1]-cuts[start-1] + helper(start,i-1,cuts,n,dp)+helper(i+1,end,cuts,n,dp));
    //     }
    //     return dp[start][end] = mini;
    // }
    // int minCost(int n, vector<int>& cuts) 
    // {
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(),0);
    //     sort(cuts.begin(),cuts.end());
    //     vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,0));
    //     for(int end = 0 ; end <= n ; end++)
    //     {
    //         for(int start = 0 ; start <end ; start++)
    //         {
    //             int mini = INT_MAX;
    //             for(int i = start;i<=end;i++)
    //             {
    //                 mini = min(mini,cuts[end+1]-cuts[start-1] + dp[start][i-1] + dp[i+1][end];
    //             }
    //             dp[start][end] = mini;
    //         }
    //     }
    //     return helper(1,cuts.size()-2,cuts,n,dp);
    // }
    int dp[101][101];
    int solve(int start_stick, int end_stick, vector<int>& cuts, int left, int right){
        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int cost = 1e9;
        
        for(int i=left; i<=right; i++){
            int left_cost = solve(start_stick, cuts[i], cuts, left, i-1);
            int right_cost = solve(cuts[i], end_stick, cuts, i+1, right);
            int curr_cost = (end_stick - start_stick) + left_cost + right_cost;
            cost = min(cost,curr_cost);
        }
        
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return solve(0, n, cuts, 0, cuts.size()-1);
    }
};