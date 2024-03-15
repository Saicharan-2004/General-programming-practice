class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        int countZero=0;
        int zeroIndex=-1;
        int product=1;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                countZero++;
                if(countZero>1)
                {
                    vector<int>r(n,0);
                    return r;
                }
                zeroIndex=i;
            }
            else
            {
                ans[i]=0;
                product*=nums[i];
            }
            if(zeroIndex!=-1)
                ans[zeroIndex]=product;
        }
        if(countZero==0)
        {
            for(int i=0;i<n;i++)
            {
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};