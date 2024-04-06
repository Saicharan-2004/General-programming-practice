class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int>temp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                temp.push(i);
            }
            if(s[i]==')')
            {
                if(!temp.empty() && s[temp.top()]=='(')
                    temp.pop();
                else
                    temp.push(i);
            }
        }
        while(!temp.empty())
        {
            s.erase(temp.top(),1);
            temp.pop();
        }
        // reverse(ans.begin(),ans.end());
        return s;
    }
};