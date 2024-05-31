class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int num = 1;
        int xoro = 0;
        for(int i = 0;i<nums.size();i++)
        {
            xoro = xoro ^ nums[i];
        }
        while(!(num & xoro))
        {
            num = num<<1;
        }
        int a=0,b=0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] & num)
            {
                a = a ^ nums[i];
            }
            else
            {
                b = b ^ nums[i];
            }
        }
        return {a,b};
    }
};