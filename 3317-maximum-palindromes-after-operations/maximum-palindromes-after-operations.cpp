class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) 
    {
        unordered_map<char,int>freq;
        vector<int>halfpairs;
        for(auto it:words)
        {
            halfpairs.push_back(it.size()/2);
            for(char c:it)
            {
                freq[c]++;
            }
        }
        int ans=0;
        for(auto it:freq)
        {
            ans+=(it.second/2);
        }
        sort(halfpairs.begin(),halfpairs.end());
        int ind=0;
        for(auto it:halfpairs)
        {
            (ans-=it);
            if(ans<0)
            {
                return ind;
            }
            else
            {
                ind++;
            }
            
        }
        return halfpairs.size();
    }
};