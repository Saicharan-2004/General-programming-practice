class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int>sense;
        for(int i = 0;i<nums.size();i++)
        {
            nums[i]  = nums[i] % 2;
        }
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                sense.push_back(i);
            }
        }
        sense.push_back(nums.size());
        vector<bool>ans;
        for(int i = 0;i<queries.size();i++)
        {
            int l1 = lower_bound(sense.begin(), sense.end(), queries[i][0]) - sense.begin();
            int l2 = lower_bound(sense.begin(), sense.end(), queries[i][1]) - sense.begin();
            if(l1 == l2)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};