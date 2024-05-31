class Solution {
public:
    bool helper(vector<int>& nums, int sum1 , int sum2, bool baari ,int i, int j )
    {
        if(i>j)
        {
            if(sum1>=sum2)
                return 1;
            return 0;
        }
        if(baari)
        {
            return helper(nums,sum1+nums[i],sum2,false,i+1,j) || helper(nums,sum1+nums[j],sum2,false,i,j-1);
        }
        else        
        {
            return helper(nums,sum1,sum2+nums[i],true,i+1,j) &&  helper(nums,sum1,sum2+nums[j],true,i,j-1);
        }        
    }
    bool predictTheWinner(vector<int>& nums) {
        return helper(nums,0,0,true,0,nums.size() - 1);
    }
};