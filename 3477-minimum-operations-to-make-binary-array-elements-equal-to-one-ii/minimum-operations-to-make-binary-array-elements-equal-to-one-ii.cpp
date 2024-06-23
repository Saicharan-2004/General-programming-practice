class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();
        int prev = 0;
        for(int i = 0;i < n;i++)
        {
            if(prev%2 == 0)
            {
                if(nums[i] == 0)
                {
                    nums[i] = 1;
                    prev++;
                }
            }
            else
            {
                if(nums[i] == 1)
                {
                    nums[i] = 0;
                    prev++;
                }
            }
        }
        return prev;
    }
};