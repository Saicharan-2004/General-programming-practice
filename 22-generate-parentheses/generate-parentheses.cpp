class Solution {
public:
    void helper(vector<string>&ans, int n,int open,int close,string str)
    {
        if(str.size()==2*n)
        {
            ans.push_back(str);
            return;
        }
        if(open<n)
        {
            helper(ans,n,open+1,close,str+"(");
        }
        if(close<open)
        {
            helper(ans,n,open,close+1,str+")");
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        helper(ans,n,0,0,"");
        return ans;
    }
};