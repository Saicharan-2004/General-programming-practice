class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int n = nums.size();
        for(auto it:nums)
        {
            if(it == 0)
            {
                zeros += 1;
            }
            else if(it == 1)
            {
                ones += 1;
            }
        }
        n -= (zeros+ones);
        int i = 0;
        while(zeros--)
        {
            nums[i] = 0;
            i++;
        }
        while(ones--)
        {
            nums[i] = 1;
            i++;
        }
        while(n--)
        {
            nums[i] = 2;
            i++;
        }
        return ;
    }
};