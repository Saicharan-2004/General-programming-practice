class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            if(s[i] == ')')
            {
                int prev = st.top();
                string tp = s.substr(prev,i-prev+1);
                reverse(tp.begin(),tp.end());
                for(int j = prev;j<=i;j++)
                {
                    s[j] = tp[j-prev];
                }
                st.pop();
            }
            else if(s[i] == '(')
                st.push(i);
        }
        string ans = "";
        for(int i = 0;i<n;i++)
        {
            if(s[i] != '('&& s[i] !=')')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};