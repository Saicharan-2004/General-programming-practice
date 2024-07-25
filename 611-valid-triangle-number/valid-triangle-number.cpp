class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int k = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                k = j+1;
                while(k<n && nums[k]<nums[i]+nums[j])
                {
                    k++;
                }
                ans += (k-j-1);
            }
        }
        return ans;
    }
};