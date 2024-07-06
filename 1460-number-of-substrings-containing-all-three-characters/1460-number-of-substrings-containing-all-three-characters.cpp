class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.size();
        unordered_map<char,int>tp;
        int right = 0;
        int left = 0;
        int ans = 0;
        while(right<n)
        {
            tp[s[right]]++;
            if(tp.size() == 3)
            {
                ans += (n-right);
                while(tp.size()>=3)
                {
                    tp[s[left]]--;
                    if(tp[s[left]]==0)
                    {
                        tp.erase(s[left]);
                    }
                    left++;
                    if(tp.size()>=3)
                    {
                        ans += n-right;
                    }
                }
            }
            right++;
        }
        return ans;
    }
};