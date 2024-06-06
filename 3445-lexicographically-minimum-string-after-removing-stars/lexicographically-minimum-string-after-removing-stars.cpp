class Solution {
public:
    string clearStars(string s) {
        set<pair<char,int>>tp;
        int n = s.length();
        string newstr = s;
        for(int i = 0;i<n;i++)
        {
            if(s[i]!='*')
            {
                tp.insert({s[i],n-i});
            }
            else
            {
                auto r = tp.begin();
                s[n-r->second]='*';
                tp.erase(tp.begin());
            }
        }
        string ans = "";
        for(auto it:s)
        {
            if(it != '*')   ans += it;
        }
        return ans;
    }
};