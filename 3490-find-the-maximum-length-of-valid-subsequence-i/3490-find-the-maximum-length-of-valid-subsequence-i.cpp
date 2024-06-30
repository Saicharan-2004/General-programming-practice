class Solution {
public:
    // int helper(int ind,bool prev,int nums,int )
    // {
    //     if(ind == nums.size())
    //     {
    //         return 0;
    //     }
    //     int nottake = helper(ind+1,prev,nums);
    //     int take = -1;
    //     if(nums[ind] % 2 == 0 && prev == false || nums[ind]%2 == 1 && prev = true)
    //     {
    //         take = max(take,1 + helper(ind+1,!prev,nums));
    //     }
    //     if(nums[ind]%2 == 0 && prev == true || nums[ind]%2 == 0 && prev = false)
    //     {

    //     }
    // }
    int maximumLength(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        bool one = true;//denotes taking even
        bool two = false;//denotes taking odd
        int seq1 = 0;
        int seq2 = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            nums[i] = nums[i]%2;
        }
        for(int i = 0;i<n;i++)
        {   
            if(nums[i] == 1 && two == false || nums[i] == 0 && two == true)
            {
                seq1++;
                two = !two;
            }
            if(nums[i] == 1 && one == false || nums[i] == 0 && one == true)
            {
                seq2++;
                one = !one;
            }
            if(nums[i])
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        return max(max(seq1,seq2),max(odd,even));
    }
};