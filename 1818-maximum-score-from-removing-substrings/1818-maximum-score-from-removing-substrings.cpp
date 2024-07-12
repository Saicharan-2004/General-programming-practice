class Solution {
private:
    int removePairs(std::string& s, char first, char second, int cost) {
        std::stack<char> st;
        int summ = 0;
        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                summ += cost;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        
        return summ;
    }
public:
    int maximumGain(std::string s, int x, int y) {
        int ans = 0;
        if (x > y) {
            ans += removePairs(s, 'a', 'b', x);
            ans += removePairs(s, 'a', 'b', y);
        } else {
            ans += removePairs(s, 'b', 'a', y);
            ans += removePairs(s, 'b', 'a', x);
        }
        return ans;
    }
};