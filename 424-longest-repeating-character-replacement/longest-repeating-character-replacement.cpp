class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        

        if(n==0)    return 0;
        int right = 0;
        int left = 0;
        int ans = 1;
        int maxFreq = 0;
        unordered_map<char,int>mp;
        while(right<n)
        {
            mp[s[right]]++;
            maxFreq=max(maxFreq,mp[s[right]]);
            int currLen = right-left+1;
            if(currLen-maxFreq>k)
            {
                mp[s[left]]--;
                left++;
            }
            else
            {
                ans = max(ans,right-left+1);
            }
            right++;
        }
        return ans;
    }
};