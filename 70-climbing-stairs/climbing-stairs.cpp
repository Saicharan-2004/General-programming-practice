class Solution {
public:
    int climbStairs(int n) 
    {
        // vector<int>dp(n+1,0);
        if(n==2)
            return 2;
        if(n==1)
            return 1;
        int prev_prev=1;
        int prev=2;
        int curr=prev;
        for(int i=3;i<=n;i++)
        {
            curr=prev+prev_prev;
            prev_prev=prev;
            prev=curr;
        }
        return curr;
    }
};