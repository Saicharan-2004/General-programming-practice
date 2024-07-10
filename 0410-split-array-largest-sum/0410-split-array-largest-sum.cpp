class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int end = accumulate(nums.begin(),nums.end(),0);
        int start = *min_element(nums.begin(),nums.end());
        int ans = INT_MAX;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            int countSegs = 1;
            int sum = 0;
            int miniSum = INT_MIN;
            for(int i = 0;i<nums.size();i++)
            {
                if(sum + nums[i] <= mid)
                {
                    sum += nums[i];
                }
                else
                {
                    countSegs++;
                    miniSum = max(miniSum,sum);
                    sum = nums[i];
                }
            }
            miniSum = max(miniSum,sum);
            if(countSegs > k)
            {
                start = mid + 1;
            }
            else
            {
                ans= min(ans,miniSum);
                end = mid - 1;
            }
        }
        return ans;
    }
};