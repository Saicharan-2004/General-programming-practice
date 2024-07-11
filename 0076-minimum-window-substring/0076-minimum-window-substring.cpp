class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int startInd = -1;
        int cnt = 0;
        int n = s.size();
        int m = t.size();
        unordered_map<char,int>mpp;
        for(auto it:t)  mpp[it]++;
        while(right<n)
        {
            if(mpp[s[right]]>0)    cnt++;
            mpp[s[right]]--;
            while(cnt == m)
            {
                if(right-left+1 < len)
                {
                    len = right - left + 1;
                    startInd = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0)
                {
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return startInd == -1 ? "":s.substr(startInd,len);
    }
};