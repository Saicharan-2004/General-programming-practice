class Solution {
public:
    int maxDepth(string s) 
    {
        stack<char>temp;
        int ans=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]== '(')
            {
                temp.push(s[i]);
            }
            else if(s[i]==')')
            {
                temp.pop();
            }
            int r=temp.size();
            ans=max(ans,r);
        }
        return ans;
    }
};