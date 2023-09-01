class Solution {
public:
    int set_bits(int i)
    {
        int count=0;
        while(i>0)
        {
            if(i%2)
            {
                count++;
            }
            i/=2;
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