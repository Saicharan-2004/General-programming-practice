class Solution {
public:
    string makeGood(string s) 
    {
        stack<int>temp;
        int n=s.length();
        // cout<<(int)'b'<<" "<<(int)'B'<<endl;
        for(int i=0;i<n;i++)
        {
            if(!temp.empty() && (temp.top() == s[i] + 32 || temp.top() == s[i] - 32))
            {
                temp.pop();
            }
            else
            {
                temp.push(s[i]);
            }
        }
        string ans="";
        while(!temp.empty())
        {
            char a=temp.top();
            ans=a+ans;
            temp.pop();
        }
        return ans;
    }
};