class Solution {
public:
    int helper(string s,int ind,int n)
    {
        if(ind==n)
        {
            return 1;
        }
        int takeOne=0;
        if(s[ind]!='0')
            takeOne=helper(s,ind+1,n);
        int taketwo=0;
        if(ind+1<n&&(s[ind]=='1'||s[ind]=='2'&&s[ind+1]<='6'))
        {
            taketwo=helper(s,ind+2,n);
        }
        return takeOne+taketwo;
    }
    int numDecodings(string s) 
    {
        int n=s.length();
        vector<int>dp(n+2,0);
        dp[n]=1;
        for(int ind=n-1;ind>=0;ind--)
        {
            int ans=0;
            if(s[ind]!='0')
                ans+=dp[ind+1];
            if(ind+1<n&&(s[ind]=='1'||s[ind]=='2'&&s[ind+1]<='6'))
            {
                ans+=dp[ind+2];
            }
            dp[ind]=ans;
        }
        return dp[0];
    }
};