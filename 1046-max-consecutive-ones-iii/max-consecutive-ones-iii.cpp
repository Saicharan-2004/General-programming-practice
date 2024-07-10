class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int right = 0;
        int left = 0;
        int maxlen = -1;
        int n = nums.size();
        while(right<n)
        {
            mpp[nums[right]]++;
            if(mpp[0]>k)
            {
                mpp[nums[left]]--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};