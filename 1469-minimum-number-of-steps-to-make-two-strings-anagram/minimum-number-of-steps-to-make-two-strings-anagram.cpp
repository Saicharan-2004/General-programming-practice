class Solution {
public:
    int minSteps(string s, string t) 
    {
        int n1=s.length();
        int n2=t.length();
        unordered_map<char,int>count1;
        unordered_map<char,int>count2;
        for(auto it:s)
        {
            count1[it]++;
        }
        for(auto it:t)
        {
            count2[it]++;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            int r=min(count1[i+'a'],count2[i+'a']);
            count1[i+'a']-=r;
            ans+=count1[i+'a'];
        }
        return ans;
    }
};