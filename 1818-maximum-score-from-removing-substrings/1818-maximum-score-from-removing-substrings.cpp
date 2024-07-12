class Solution {
public:
    pair<string,int> helper(string s,char first,char second,int val)
    {
        stack<int>st;
        int n = s.size();
        int count = 0;
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
        return {str,count};
    }
    int maximumGain(string s, int x, int y) {
        int count = 0;
        if(x>y)
        {
            auto st = helper(s,'a','b',x);
            count += st.second;
            auto r = helper(st.first,'a','b',y);
            count += r.second;
        }
        else
        {
            auto st = helper(s,'b','a',y);
            count += st.second;
            auto r = helper(st.first,'b','a',x);
            count += r.second;
        }
        return count;
    }
};