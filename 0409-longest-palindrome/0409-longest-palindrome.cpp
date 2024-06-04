class Solution {
public:
    int longestPalindrome(string s) 
    {
        map<int,int>tp;
        for(auto it:s)
        {
            tp[it]++;
        }
        int ans = 0;
        int counter = 0;
        for(auto it:tp)
        {
            if(it.second % 2 == 0)
            {
                ans +=it.second;
            }
            else
            {
                counter = 1;
                ans += it.second - 1;
            }
        }
        return ans + counter;
    }
};