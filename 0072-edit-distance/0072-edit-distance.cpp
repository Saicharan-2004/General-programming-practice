class Solution {
public:
    int helper(string str1,string str2,int ind1,int ind2,int n,int m,vector<vector<int>>&dp)
    {
        if(ind2==0)
        {
            return ind1;
        }
        else if(ind1==0)
        {
            return ind2;
        }
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        if(str1[ind1-1]==str2[ind2-1])
        {
            return dp[ind1][ind2]= helper(str1,str2,ind1-1,ind2-1,n,m,dp);
        }
        else
        {
            return dp[ind1][ind2]= 1+min(helper(str1,str2,ind1,ind2-1,n,m,dp),min(helper(str1,str2,ind1-1,ind2-1,n,m,dp),helper(str1,str2,ind1-1,ind2,n,m,dp)));
        }
    }
    int minDistance(string word1, string word2) 
    {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(n==0)
        {
            return m;
        }
        if(m==0)
        {
            return n;
        }
        return helper(word1,word2,n,m,n,m,dp);
    }
};