class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        for(int i = 0;i < n;i++)
        {
            if(prev%2 == 0)
            {
                if(nums[i] == 0)
                {
                    prev++;
                }
            }
            else
            {
                if(nums[i] == 1)
                {
                    prev++;
                }
            }
        }
        return prev;
    }
};