class Solution {
public:
    int minInsertions(string s) 
    {
        string s2=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        // int m=s2.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s2[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                else
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return n-prev[n];
    }
};