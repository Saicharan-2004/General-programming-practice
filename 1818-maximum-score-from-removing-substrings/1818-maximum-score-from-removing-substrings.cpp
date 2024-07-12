class Solution {
public:
    int count = 0;
    string helper(string s,char first,char second,int val)
    {
        stack<int>st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && s[i] == second && st.top() == first)
            {
                st.pop();
                count += val;
            }
            else
            {
                st.push(s[i]);
            }
        }
        string str = "";
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        return str;
    }
    int maximumGain(string s, int x, int y) {
        if(x>y)
        {
            string st = helper(s,'a','b',x);
            string r = helper(st,'a','b',y);
        }
        else
        {
            string st = helper(s,'b','a',y);
            string r = helper(st,'b','a',x);
        }
        return count;
    }
};