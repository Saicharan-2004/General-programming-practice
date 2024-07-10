class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mpp;
        int left = 0;
        int right = 0;
        int n = s.size();
        int maxlen = -1;
        int maxFreq = -1;
        while(right<n)
        {
            maxFreq=max(maxFreq,++mpp[s[right]]);
            while((right-left+1)-maxFreq>k)
            {
                mpp[s[left]]--;
                maxFreq = 0;
                for(auto it:mpp)
                {
                    maxFreq = max(maxFreq,it.second);
                }
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};