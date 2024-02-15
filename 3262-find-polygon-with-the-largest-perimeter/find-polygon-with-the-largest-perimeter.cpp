class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        long long int sum=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<(sum))
            {
                ans=sum+nums[i];
            }
            sum+=nums[i];
        }
        return ans;
    }
};