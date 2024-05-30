class Solution {
public:
    int helper(int i,int j,string s1,string s2)
    {
        if(j == 0)
        {
            return i;
        }
        if(i == 0)
        {
            return j;
        }
        if(s1[i-1] == s2[j-1])
        {
            return helper(i-1,j-1,s1,s2);
        }
        else
        {
            return 1+min(helper(i-1,j-1,s1,s2),min(helper(i,j-1,s1,s2),helper(i-1,j,s1,s2)));
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i = 0;i<=m;i++)
        {
            prev[i]=i;
        }
        if(n == 0)
        {
            return m;
        }
        if(m == 0)
        {
            return n;
        }
        for(int ind1 = 1;ind1<=n;ind1++)
        {
            for(int ind2 = 1;ind2<=m;ind2++)
            {
                curr[0]=ind1;
                int i = ind1;
                int j = ind2;
                if(s1[ind1-1] == s2[ind2-1])
                {
                    curr[j]=prev[j-1];
                }
                else
                {
                    curr[j]=1+min(prev[j-1],min(curr[j-1],prev[j]));
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};