class Solution {
public:
    int helper(vector<int>arr,int goal)
    {
        if(goal<0)  return 0;
        int n = arr.size();
        int r=0;
        int l=0;
        int count=0;
        int sum = 0;
        while(r<n)
        {
            sum+=arr[r];
            while(sum>goal)
            {
                sum-=arr[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};