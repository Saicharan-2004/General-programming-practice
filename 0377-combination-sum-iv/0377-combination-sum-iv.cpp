class Solution {
public:
    uint helper(vector<int>arr,int tar,vector<uint>&dp)
    {
        if(tar==0)
            return 1;
        int ans=0;
        for(int it:arr)
        {
            if(it<=tar)
            {
                ans+=helper(arr,tar-it,dp);
            }
        }
        return dp[tar]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<uint>dp(target+1,0);
        dp[0]=1;
        for(int tar=1;tar<=target;tar++)
        {
            int ans=0;
            for(int it:nums)
            {
                if(it<=tar)
                {
                    ans+=dp[tar-it];
                }
            }
            dp[tar]=ans;
        }
        return dp[target];
        // return helper(nums,target,dp);
        // vector<int>prev(target+1,0),curr(target+1,0);
        // for(int i=0;i<=target;i++)
        // {
        //     prev[i]=((i%nums[0])==0);
        // }
        // for(int ind=1;ind<nums.size();ind++)
        // {
        //     for(int tar=0;tar<=target;tar++)
        //     {
        //         int nottake=prev[tar];
        //         int take=0;
        //         if(tar>=nums[ind])
        //         {
        //             take=curr[tar-nums[ind]];
        //         }
        //         curr[tar]=take+nottake;
        //     }
        //     prev=curr;
        // }
        // return prev[target];
    }
};