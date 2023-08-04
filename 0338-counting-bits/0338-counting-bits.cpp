class Solution {
public:
    int set_bits(int i)
    {
        int count=0;
        while(i>0)
        {
            i=(i)&(i-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) 
    {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(set_bits(i));
        }
        return ans;
    }
};