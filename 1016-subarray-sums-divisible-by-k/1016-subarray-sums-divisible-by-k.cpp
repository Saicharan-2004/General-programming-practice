class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        // for(auto it:nums)
        // {
        //     if(it%k == 0)   ans+=1;
        // }
        for(int i = 1;i<nums.size();i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }
        nums.push_back(0);
        unordered_map<int,int>tp;
        for(auto it:nums)
        {
            it = (it % k + k) % k;
            tp[it]++;
        }
        for(auto it:tp)
        {
            // if(it.first % k == 0)
            // {
            //     if(it.second == 1)
            //     {
            //         ans += 1;
            //     }
            // }
            int num = it.second*(it.second-1);
            num/=2;
            ans+=num;
        }
        return ans;
    }
};