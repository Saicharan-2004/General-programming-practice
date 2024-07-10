class Solution {
public:
    int helper(vector<int>&nums,int k)
    {
        int end = accumulate(nums.begin(),nums.end(),0);
        int start = *max_element(nums.begin(),nums.end());
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            int countSegs = 1;
            int sum = 0;
            for(int i = 0;i<nums.size();i++)
            {
                if(sum + nums[i] <= mid)
                {
                    sum += nums[i];
                }
                else
                {
                    countSegs++;
                    sum = nums[i];
                }
            }
            if(countSegs > k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
    int splitArray(vector<int>& nums, int k) {
        
        return helper(nums,k);
    }
};