class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto upper = upper_bound(nums.begin(),nums.end(),target);
        auto lower = lower_bound(nums.begin(),nums.end(),target);
        int one = int(lower-nums.begin());
        int two = int(upper-nums.begin());
        if(one >= nums.size())
        {
            return {-1,-1};
        }
        if(nums[one] != target) return {-1,-1};
        return {one,two-1};
    }
};