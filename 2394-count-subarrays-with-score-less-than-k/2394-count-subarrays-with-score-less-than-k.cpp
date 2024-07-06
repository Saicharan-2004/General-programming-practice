class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int count = 0;
        int n = nums.size();
        int r = 0;
        int l = 0;
        long long int sum = 0;
        while(r<n)
        {
            sum += nums[r];
            int currLen = r-l+1;
            while( (currLen)*sum >= k)
            {
                sum = sum - nums[l];
                l++;
                currLen=r-l+1;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
};