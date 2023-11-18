class Solution {
public:
    int maxFrequency(vector<int>& nums, long  k) 
    {
        sort(nums.begin(),nums.end());
        long n=nums.size();
        long left=0;
        long curr=0;
        for(int right=0;right<n;right++)
        {
            curr+=nums[right];
            if((right-left+1)*nums[right]-curr>k)
            {
                curr-=nums[left];
                left++;
            }
        }
        return n-left;
        // vector<long>prev(n,0);
        // prev[0]=0;
        // for(int i=0;i<n-1;i++)
        // {
        //     prev[i+1]=prev[i]+nums[i];
        // }
        // long maxi=1;
        // for(long i=1;i<n;i++)
        // {
        //     long r=i*nums[i]-prev[i];
        //     if(r<=k)
        //     {
        //         maxi=max(maxi,i+1);
        //     }
        //     else
        //     {
        //         return maxi;
        //     }
        // }
        // return maxi;
    }
};