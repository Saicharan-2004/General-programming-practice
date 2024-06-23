class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size() - 1;
        double ans = INT_MAX;
        while(start < end)
        {
            ans = min(ans,(nums[start]+nums[end])/(double)2);
            start++;
            end--;
        }
        return ans;
    }
};