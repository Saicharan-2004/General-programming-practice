class Solution {
public:
    int isSubsequence(string s,string t)
    {
        int i = 0;
        int j = 0;
        while(i<s.size() && j<t.size())
        {
            if(s[i] == t[j])
            {
                // cout<<j<<" j ";
                i++;
                j++;
            }
            else
            {
                // cout<<i<<" i ";
                i++;
            }
        }
        // cout<<j<<" ";
        return j;
    }
    int appendCharacters(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // int ans = 0;
        // for(int i = 0;i<m;i++)
        // {
        //     string r = t.substr(0,i+1);
        //     if(isSubsequence(s,r))
        //         ans++;
        // }
        // // return max(0,m-ans);
        return m-isSubsequence(s,t);
    }
};