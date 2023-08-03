class Solution {
public:
    int helper(vector<vector<int>>questions,int ind,int n,vector<int>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int nottake=helper(questions,ind+1,n,dp);
        int take=INT_MIN;
        if(ind<n)
        {
            take=questions[ind][0]+helper(questions,ind+questions[ind][1]+1,n,dp);
        }
        return dp[ind]= max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n=questions.size();
        vector<long long>dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            long long int nottake=dp[ind+1];
            long long int take=-1e8;
            if(ind+questions[ind][1]+1<n)
            {
                take=questions[ind][0]+dp[ind+questions[ind][1]+1];
            }
            else
            {
                take=questions[ind][0];
            }
            dp[ind]=max(take,nottake);
        }
        return dp[0];
    }
};