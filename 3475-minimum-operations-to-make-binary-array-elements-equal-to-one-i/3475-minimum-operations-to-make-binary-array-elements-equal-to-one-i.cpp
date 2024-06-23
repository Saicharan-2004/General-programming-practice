class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();
        for(int i = 0;i < n - 2;i++)
        {
            if(nums[i] == 0)
            {
                int j = i;
                while(j<i+3 && j < n)
                {
                    if(nums[j] == 0)
                    {
                        nums[j] = 1;
                    }
                    else
                    {
                        nums[j] = 0;
                    }
                    j++;
                }
                ops++;
            }
        }
        for(auto it:nums)
        {
            if(it == 0) return -1;
        }
        return ops;
    }
};