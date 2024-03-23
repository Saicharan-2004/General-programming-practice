class Solution {
public:
    unordered_set<string>tp;
    vector<string>helper(int n)
    {
        if(n==1)
        {
            return {"()"};
        }
        vector<string>temp=helper(n-1);
        int nn=temp.size();
        vector<string>temp1;
        for(int i=0;i<nn;i++)
        {
            string s=temp[i];
            temp1.push_back("()"+s);
            if(tp.find(temp1.back())==tp.end())
            {
                tp.insert(temp1.back());
            }
            else
            {
                temp1.pop_back();
            }
            temp1.push_back(s+"()");
            if(tp.find(temp1.back())==tp.end())
            {
                tp.insert(temp1.back());
            }
            else
            {
                temp1.pop_back();
            }
            for(int j=0;j<s.size();j++)
            {
                temp1.push_back(s.substr(0,j+1)+"()"+s.substr(j+1));
                if(tp.find(temp1.back())==tp.end())
                {
                    tp.insert(temp1.back());
                }
                else
                {
                    temp1.pop_back();
                }
            }
        }
        return temp1;
    }
    vector<string> generateParenthesis(int n) 
    {
        return helper(n);
    }
};