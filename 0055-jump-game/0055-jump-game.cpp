class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxjump = 0;
        for(int i = 0;i<n;i++)
        {
            if(maxjump < i) return false;
            maxjump = max(maxjump,nums[i]+i);
            
        }
        return true;
    }
};