class Solution {
public:
    int jump(vector<int>& nums) {
        // int maxjumps = 0;
        int min = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while(right<n-1)
        {
            int farthest = 0;
            for(int i = left ;i<=right;i++)
            {
                farthest = max(farthest,nums[i]+i);
            }
            left = right + 1;
            right = farthest;
            min++;
        }
        return min;
    }
};