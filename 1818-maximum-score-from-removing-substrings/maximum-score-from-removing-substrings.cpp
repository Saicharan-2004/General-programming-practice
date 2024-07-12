class Solution {
public:
    pair<string,int> removePairs(string s, char first, char second, int cost) {
        stack<char> st;
        int summ = 0;
        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                summ += cost;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string stri = "";
        while (!st.empty()) {
            stri += st.top();
            st.pop();
        }
        return {stri,summ};
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x > y) {
            auto res= removePairs(s, 'a', 'b', x);
            ans += res.second;
            auto res2= removePairs(res.first, 'a', 'b', y);
            ans += res2.second;
        } else {
            auto res= removePairs(s, 'b', 'a', y);
            ans += res.second;
            auto res2= removePairs(res.first, 'b', 'a', x);
            ans += res2.second;
        }
        return ans;
    }
};
