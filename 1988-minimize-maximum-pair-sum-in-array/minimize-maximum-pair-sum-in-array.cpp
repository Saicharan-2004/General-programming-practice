class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int st=0;
        int en=nums.size()-1;
        while(st<en)
        {
            maxi=max(maxi,nums[st]+nums[en]);
            st++;
            en--;
        }
        return maxi;
    }
};