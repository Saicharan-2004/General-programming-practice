class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(nums[i]%2)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }
        for(int i = 1;i<n;i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }
        unordered_map<int,int>tp;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] == k)
            {
                ans++;
            }
            if(tp.find(nums[i] - k) != tp.end())
            {
                ans+=tp[nums[i] - k];
            }
            tp[nums[i]]++;
        }
        return ans;
    }
};