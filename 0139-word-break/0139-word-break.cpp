class Solution {
public:
    struct hash_pair 
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            if (hash1 != hash2) {
                return hash1 ^ hash2;             
            }
            
            // If hash1 == hash2, their XOR is zero.
            return hash1;
        }
    };
    bool helper(set<string>words,string s,int ind,int n,vector<int>&dp)
    {
        if(ind==n)
        {
            return 1;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        string temp="";
        for(int j=ind;j<s.length();j++)
        {
            temp=temp+s[j];
            if(words.find(temp)!=words.end())
            {
                if(helper(words,s,j+1,n,dp))
                {
                    return dp[ind]= true;
                }
            }
        }
        return dp[ind]= false;
    }
    bool wordBreak(string s, vector<string>& words) 
    {
        int n=words.size();
        vector<int>dp(s.length()+1,-1);
        set<string>rt(words.begin(),words.end());
        return helper(rt,s,0,s.length(),dp);
    }
};