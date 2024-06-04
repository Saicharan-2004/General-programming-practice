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
                counter++;
                ans += it.second - 1;
            }
        }
        if(counter > 0)
        {
            return ans + 1;
        }
        else
        {
            return ans;
        }
    }
};