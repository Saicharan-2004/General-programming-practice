class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>lis(n);
        vector<int>lds(n);
        for(int i=0;i<n;i++)
        {
            lis[i]=1;
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i] = max(lis[i],1 + lis[j]);
                }
            }
        }
        for(int i = n-1;i>=0;i--)
        {
            lds[i]=1;
            for(int j = i+1;j<n;j++)
            {
                if(nums[j]<nums[i])
                {
                    lds[i] = max(lds[i],1 + lds[j]);
                }
            }
        }
        int ans = -1;
        for(auto it : lis)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it :lds)
        {
            cout<<it<<" ";
        }
        for(int i = 0;i<n;i++)
        {
            if(lis[i]>1 && lds[i] >1)
                ans = max (ans , (lis[i] + lds[i] - 1));
        }
        return n-ans;
    }
};