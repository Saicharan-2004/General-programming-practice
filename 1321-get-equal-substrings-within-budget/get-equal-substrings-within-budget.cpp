class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.length();
        int maxi = 0;
        int start = 0;
        int sum = 0;
        int end = 0;
        while(end < n)
        {
            sum+=abs(s[end]-t[end]);
            while(sum > maxCost)
            {
                sum -= abs(s[start]-t[start]);
                start++;
            }
            maxi = max(maxi, end - start + 1);
            end++;
        }
        return maxi;
    }
};