class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>temp;
        int n=s.length();
        if(n%2!=0)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{'||s[i]=='('||s[i]=='[')
            {
                temp.push(s[i]);
            }
            if(s[i]=='}')
            {
                if(temp.empty())
                {
                    return false;
                }
                if(temp.top()!='{')
                {
                    return false;
                }
                else if(!temp.empty())
                {
                    temp.pop();
                }
            }
            if(s[i]==')')
            {
                if(temp.empty())
                {
                    return false;
                }
                if(temp.top()!='(')
                {
                    return false;
                }
                else if(!temp.empty())
                {
                    temp.pop();
                }
            }
            if(s[i]==']')
            {
                if(temp.empty())
                {
                    return false;
                }
                if(temp.top()!='[')
                {
                    return false;
                }
                else if(!temp.empty())
                {
                    temp.pop();
                }
            }
        }
        if(temp.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};