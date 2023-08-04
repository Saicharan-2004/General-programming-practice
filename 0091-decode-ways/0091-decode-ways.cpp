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
        // int n=s.length();
        // vector<int>dp(n+2,0);
        // dp[n]=1;
        int front=1;
        int front_front=1;
        int curr=1;
        for(int ind=s.length()-1;ind>=0;ind--)
        {
            int ans=0;
            if(s[ind]!='0')
                ans+=front;
            if(ind+1<s.length()&&(s[ind]=='1'||s[ind]=='2'&&s[ind+1]<='6'))
            {
                ans+=front_front;
            }
            curr=ans;
            front_front=front;
            front=curr;
        }
        return curr;
    }
};