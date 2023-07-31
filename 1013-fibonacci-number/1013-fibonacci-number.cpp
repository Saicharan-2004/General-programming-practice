class Solution {
public:
    int fib(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        vector<int>dp(n+1,0);
        int prev_prev=0;
        int prev=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=prev+prev_prev;
            prev_prev=prev;
            prev=dp[i];
        }
        return prev;
    }
};