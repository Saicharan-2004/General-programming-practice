class Solution {
public:
    int helper(int low,int high,int zero,int one,int ind)
    {
        if(ind>high)
        {
            return 0;
        }
        int ans=0;
        if(ind>=low)
        {
            ans+=1;
        }
        int takezero=0;
        int takeone=0;
        if(zero>0)
            takezero=helper(low,high,zero,one,ind+zero);
        if(one>0)
            takeone=helper(low,high,zero,one,ind+one);
        return ans+=takezero+takeone;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int mod=1e9+7;
        vector<int>dp(high+max(zero,one)+1,0);
        dp[high]=1;
        for(int i=high-1;i>=0;i--)
        {
            int ans=0;
            if(i>=low)
            {
                ans+=1;
            }
            int takezero=0;
            int takeone=0;
            if(i+zero<=high)
                takezero=dp[i+zero];
            if(i+one<=high)
                takeone=dp[i+one];
            dp[i]=(takeone+takezero+ans)%mod;
        }
        return dp[0]%mod;
    }
};