class Solution {
public:
    vector<string>ans;
    void helper(int ind,string str,unordered_set<string>dict,string s)
    {
        if(ind >= str.length())
        {
            ans.push_back(s);
            return ;
        }
        for(int i = ind + 1;i<=str.length(); i++)
        {
            string r = str.substr(ind,i - ind);
            cout<<r<<" * ";
            if(dict.find(r) != dict.end())
            {
                string temp = s;
                if(!temp.empty())
                {
                    temp+=" ";
                }
                temp+=r;
                helper(i,str,dict,temp);
                temp = s;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string>tp(wordDict.begin(),wordDict.end());
        helper(0,s,tp,"");
        return ans;
    }
};